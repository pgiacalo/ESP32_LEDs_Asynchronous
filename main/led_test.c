#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_control.h"

void app_main(void) {
    // Initialize the LEDs
    initializeLEDs();
    
    // Create the LED control task
    xTaskCreate(controlLEDs, "LED Control Task", 2048, NULL, 1, NULL);
    
    // Set custom intervals
    setRedLEDBrightness(128); // Example: set red LED brightness to 128
    setGreenLEDBrightness(64); // Example: set green LED brightness to 64
    setBlueLEDBrightness(255); // Example: set blue LED brightness to 255
    
    // Main loop equivalent
    while (true) {
        // Example sequences to test LED behaviors and colors
        printf("-------------------------------------------\n");

        // Turn the LED off
        printf("Test: LED Off\n");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

        // Turn the LED on with different colors
        printf("Test: LED On Red\n");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_ON;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED On Green\n");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_ON;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED On Blue\n");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_ON;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

        // Set the LED to slow blink
        printf("Test: LED Slow Blink Red\n");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED Slow Blink Green\n");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED Slow Blink Blue\n");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        printf("\n");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

        // Set the LED to blink
        printf("Test: LED Blink Red\n");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED Blink Green\n");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED Blink Blue\n");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

        // Set the LED to fast blink
        printf("Test: LED Fast Blink Red\n");
        ledColor = LED_COLOR_RED;
        ledBehavior = LED_BEHAVIOR_FAST_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED Fast Blink Green\n");
        ledColor = LED_COLOR_GREEN;
        ledBehavior = LED_BEHAVIOR_FAST_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
        
        printf("Test: LED Fast Blink Blue\n");
        ledColor = LED_COLOR_BLUE;
        ledBehavior = LED_BEHAVIOR_FAST_BLINK;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("\n");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

        // Set the LED to cycle through colors
        printf("Test: LED Cycle\n");
        ledBehavior = LED_BEHAVIOR_CYCLE;
        vTaskDelay(6000 / portTICK_PERIOD_MS);
        printf("\n");
        ledBehavior = LED_BEHAVIOR_OFF;
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

        // Repeat the sequence
    }
}
