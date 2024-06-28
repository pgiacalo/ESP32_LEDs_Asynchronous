#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "led_control.h"

#define TAG "LED_TEST"

// Function prototypes
void setupLEDs();
void ledTestTask(void *pvParameters);

void app_main() {
    // Create the LED control task
    xTaskCreate(controlLEDs, "LED Control Task", 1024, NULL, 1, NULL);

    setupLEDs();

    // Create the LED test task
    xTaskCreate(ledTestTask, "LED Test Task", 2048, NULL, 1, NULL); 
}

void setupLEDs() {
    // Initialize the LEDs
    initializeLEDs();
    // Set custom intervals and brightness levels
    setRedLEDBrightness(128);  // Example: set red LED brightness to 128
    setGreenLEDBrightness(64);  // Example: set green LED brightness to 64
    setBlueLEDBrightness(255);  // Example: set blue LED brightness to 255
}

void ledTestTask(void *pvParameters) {
    while (true) {
        // Example sequences to test LED behaviors and colors
        ESP_LOGI(TAG, "Test: LEDs Off");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(2000 / portTICK_PERIOD_MS);

        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay

        // Turn the LED on with different colors
        ESP_LOGI(TAG, "Test: LED On Red");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_ON;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED On Green");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_ON;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED On Blue");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_ON;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay

        // Set the LED to slow blink
        ESP_LOGI(TAG, "Test: LED Slow Blink Red");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED Slow Blink Green");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED Slow Blink Blue");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay

        // Set the LED to blink
        ESP_LOGI(TAG, "Test: LED Blink Red");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED Blink Green");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED Blink Blue");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay

        // Set the LED to fast blink
        ESP_LOGI(TAG, "Test: LED Fast Blink Red");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_FAST_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED Fast Blink Green");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_FAST_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay
        
        ESP_LOGI(TAG, "Test: LED Fast Blink Blue");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_FAST_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay

        // Set the LED to cycle through colors
        ESP_LOGI(TAG, "Test: LED Cycle");
        ledBehavior = LED_BEHAVIOR_CYCLE;
        vTaskDelay(6000 / portTICK_PERIOD_MS);
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second delay

        // Repeat the sequence
    }
}


