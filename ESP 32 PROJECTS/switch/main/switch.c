#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRtos.h"
#include "freertos/task.h"

#define LED_PIN 2
#define BUTTON_PIN 4


void app_main(void)
{
    //reset pins 
    gpio_reset_pin(LED_PIN);
    gpio_reset_pin(BUTTON_PIN);

    // configure button pin 
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT); // input 
    gpio_set_pull_mode(BUTTON_PIN, GPIO_PULLUP_ONLY);
    // internal pullup activated for active low button concept

    // configure led pin
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // button state
    int led_state=0;   // 0=OFF, 1=ON

    while(1)
    {
        if(gpio_get_level(BUTTON_PIN)==0)
        {
            vTaskDelay(200 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN, led_state);
            led_state=!led_state;

        }
    }



}
