#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_client.h"
#include "esp_adc/adc_oneshot.h"
#include "driver/gpio.h"
#include "cJSON.h"
#include "esp_tls.h"
#include "esp_crt_bundle.h"

#define WIFI_SSID               "KOKADANS"
#define WIFI_PASS               "kokadans"
#define LM35_CONTROL_PIN        GPIO_NUM_33
#define FIREBASE_URL            "https://esp32lm35-5122c-default-rtdb.asia-southeast1.firebasedatabase.app/sensor_data.json"
#define SENSOR_READ_INTERVAL_MS 5000
#define TEMP_CALIBRATION_OFFSET 9.5

static const char *TAG = "IOT_APP";

// Wi-Fi Event Handler
static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data) {

    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        ESP_LOGI(TAG, "WiFi Started. Connecting...");
        esp_wifi_connect();

    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        ESP_LOGE(TAG, "❌ Wi-Fi disconnected. Retrying...");
        esp_wifi_connect();

    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "✅ Got IP: " IPSTR, IP2STR(&event->ip_info.ip));
    }
}

// Wi-Fi Initialization
void wifi_init_sta(void) {
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL, NULL));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
            .threshold.authmode = WIFI_AUTH_OPEN,
            .pmf_cfg = {
                .capable = true,
                .required = false
            },
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "Wi-Fi Init Finished.");
}

// GPIO Initialization
void gpio_init_lm35_control(void) {
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LM35_CONTROL_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    ESP_ERROR_CHECK(gpio_config(&io_conf));
    ESP_LOGI(TAG, "GPIO33 initialized for LM35 control");
}

// LM35 Power Control
void lm35_power_control(bool enable) {
    if (enable) {
        gpio_set_level(LM35_CONTROL_PIN, 1);
        ESP_LOGI(TAG, "LM35 Power: ON");
    } else {
        gpio_set_level(LM35_CONTROL_PIN, 0);
        ESP_LOGI(TAG, "LM35 Power: OFF");
    }
}

// Upload to Firebase (DEBUG ENHANCED)
void upload_sensor_data(float temperature, int raw_adc) {

    ESP_LOGI(TAG, "Preparing JSON...");

    cJSON *root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "temperature_c", temperature);
    cJSON_AddNumberToObject(root, "raw_adc", raw_adc);
    cJSON_AddNumberToObject(root, "timestamp", (double)time(NULL));
    cJSON_AddStringToObject(root, "status", "active");

    char *json_string = cJSON_PrintUnformatted(root);

    ESP_LOGI(TAG, "JSON: %s", json_string);

    esp_http_client_config_t config = {
        .url = FIREBASE_URL,
        .method = HTTP_METHOD_PATCH,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .skip_cert_common_name_check = true,
    };

    ESP_LOGI(TAG, "Connecting to Firebase...");

    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, json_string, strlen(json_string));

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        int status_code = esp_http_client_get_status_code(client);
        int content_length = esp_http_client_get_content_length(client);

        ESP_LOGI(TAG, "Firebase Status Code: %d", status_code);
        ESP_LOGI(TAG, "Response Length: %d", content_length);

        if (status_code == 200) {
            ESP_LOGI(TAG, "✅ Data uploaded successfully");
        } else {
            ESP_LOGE(TAG, "⚠️ Unexpected response from Firebase");
        }

    } else {
        ESP_LOGE(TAG, "❌ HTTP request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
    cJSON_Delete(root);
    free(json_string);
}

// MAIN FUNCTION
void app_main(void) {

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_sta();
    gpio_init_lm35_control();

    adc_oneshot_unit_handle_t adc1_handle;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_12,
        .atten = ADC_ATTEN_DB_11,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL_6, &config));

    lm35_power_control(true);

    while (1) {
        int raw_val;
        adc_oneshot_read(adc1_handle, ADC_CHANNEL_6, &raw_val);

        float milliVolts = (raw_val * 3300.0) / 4095.0;
        float tempC = (milliVolts / 10.0) + TEMP_CALIBRATION_OFFSET;

        ESP_LOGI("LM35", "Raw: %d, Temp: %.2f °C", raw_val, tempC);

        upload_sensor_data(tempC, raw_val);

        vTaskDelay(pdMS_TO_TICKS(SENSOR_READ_INTERVAL_MS));
    }
}