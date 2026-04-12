#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_client.h"
#include "driver/gpio.h"
#include "cJSON.h"
#include "esp_tls.h"
#include "esp_crt_bundle.h"

// ================= CONFIG =================
#define WIFI_SSID   "Galaxy A13C800"
#define WIFI_PASS   "123456789"

#define LED_PIN     GPIO_NUM_2

// 🔥 Replace this with your Firebase URL
#define SERVER_URL "https://aneeskokadan.com/wp-json/iot/v1/led"
static const char *TAG = "LED_SERVER";


// ================= WIFI =================
static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data) {

    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        ESP_LOGI(TAG, "WiFi Started...");
        esp_wifi_connect();

    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        ESP_LOGE(TAG, "WiFi Disconnected... Retrying");
        esp_wifi_connect();

    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "Got IP: " IPSTR, IP2STR(&event->ip_info.ip));
    }
}

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
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
}


// ================= GPIO =================
void gpio_init_led(void) {

    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LED_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&io_conf);

    ESP_LOGI(TAG, "LED GPIO Initialized");
}


// ================= FIREBASE =================
void get_led_state_from_server() {

    esp_http_client_config_t config = {
        .url = SERVER_URL,
        .method = HTTP_METHOD_GET,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .skip_cert_common_name_check = true,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);

    // 🔥 OPEN CONNECTION MANUALLY
    esp_err_t err = esp_http_client_open(client, 0);

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to open HTTP connection");
        esp_http_client_cleanup(client);
        return;
    }

    int content_length = esp_http_client_fetch_headers(client);

    char buffer[512];
    int total_read = 0;
    int read_len;

    memset(buffer, 0, sizeof(buffer));

    while ((read_len = esp_http_client_read(client, buffer + total_read, sizeof(buffer) - total_read - 1)) > 0) {
        total_read += read_len;
    }

    buffer[total_read] = '\0';

    ESP_LOGI(TAG, "Bytes Read = %d", total_read);
    ESP_LOGI(TAG, "Firebase Response = %s", buffer);

    if (total_read == 0) {
        ESP_LOGE(TAG, "Empty response");
        esp_http_client_close(client);
        esp_http_client_cleanup(client);
        return;
    }

    // JSON parsing
    cJSON *root = cJSON_Parse(buffer);

    if (root) {
        cJSON *state = cJSON_GetObjectItem(root, "state");

    if (state && state->valuestring) {

            if (strcmp(state->valuestring, "ON") == 0) {
                gpio_set_level(LED_PIN, 1);
                ESP_LOGI(TAG, "LED ON");
            } else {
                gpio_set_level(LED_PIN, 0);
                ESP_LOGI(TAG, "LED OFF");
            }
        }
        cJSON_Delete(root);
    } else {
        ESP_LOGE(TAG, "JSON Parse Failed");
    }

    esp_http_client_close(client);
    esp_http_client_cleanup(client);
}


// ================= MAIN =================
void app_main(void) {

    ESP_ERROR_CHECK(nvs_flash_init());

    wifi_init_sta();
    gpio_init_led();

    while (1) {

        // 🔥 Read SERVER and control LED
        get_led_state_from_server();

        vTaskDelay(pdMS_TO_TICKS(2000)); // check every 2 sec
    }
}