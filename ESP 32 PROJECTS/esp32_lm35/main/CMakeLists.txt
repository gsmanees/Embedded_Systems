   idf_component_register(SRCS "esp32_lm35.c"
                        INCLUDE_DIRS "."
                        REQUIRES nvs_flash esp_wifi esp_http_client esp_adc json esp-tls driver)
