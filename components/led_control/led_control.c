#include "led_control.h"

// Shared variables
volatile LedBehavior ledBehavior = LED_BEHAVIOR_OFF;
volatile LedColor ledColor = LED_COLOR_RED;

// Brightness variables (0-255)
static int redLEDBrightness = 255;
static int greenLEDBrightness = 255;
static int blueLEDBrightness = 255;

// Interval variables
static int blinkInterval = 250;  // Blinking interval in milliseconds
static int fastBlinkInterval = 100;  // Blinking interval in milliseconds
static int slowBlinkInterval = 1000;  // Blinking interval in milliseconds
static int cycleInterval = 1000; // Cycle thru 3 colors interval in milliseconds

void initializeLEDs() {
    gpio_reset_pin(RED_LED_PIN);
    gpio_set_direction(RED_LED_PIN, GPIO_MODE_OUTPUT);
    
    gpio_reset_pin(GREEN_LED_PIN);
    gpio_set_direction(GREEN_LED_PIN, GPIO_MODE_OUTPUT);
    
    gpio_reset_pin(BLUE_LED_PIN);
    gpio_set_direction(BLUE_LED_PIN, GPIO_MODE_OUTPUT);
}

void setRedLEDBrightness(int brightness) {
    redLEDBrightness = brightness;
}

void setGreenLEDBrightness(int brightness) {
    greenLEDBrightness = brightness;
}

void setBlueLEDBrightness(int brightness) {
    blueLEDBrightness = brightness;
}

int getRedLEDBrightness() {
    return redLEDBrightness;
}

int getGreenLEDBrightness() {
    return greenLEDBrightness;
}

int getBlueLEDBrightness() {
    return blueLEDBrightness;
}

void setBlinkInterval(int interval) {
    blinkInterval = interval;
}

void setFastBlinkInterval(int interval) {
    fastBlinkInterval = interval;
}

void setSlowBlinkInterval(int interval) {
    slowBlinkInterval = interval;
}

void setCycleInterval(int interval) {
    cycleInterval = interval;
}

int getBlinkInterval() {
    return blinkInterval;
}

int getFastBlinkInterval() {
    return fastBlinkInterval;
}

int getSlowBlinkInterval() {
    return slowBlinkInterval;
}

int getCycleInterval() {
    return cycleInterval;
}

void controlLEDs(void *pvParameters) {
    while (true) {
        switch (ledBehavior) {
            case LED_BEHAVIOR_OFF:
                gpio_set_level(RED_LED_PIN, 0);
                gpio_set_level(GREEN_LED_PIN, 0);
                gpio_set_level(BLUE_LED_PIN, 0);
                break;
            case LED_BEHAVIOR_ON:
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(RED_LED_PIN, 1);
                    gpio_set_level(GREEN_LED_PIN, 0);
                    gpio_set_level(BLUE_LED_PIN, 0);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(RED_LED_PIN, 0);
                    gpio_set_level(GREEN_LED_PIN, 1);
                    gpio_set_level(BLUE_LED_PIN, 0);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(RED_LED_PIN, 0);
                    gpio_set_level(GREEN_LED_PIN, 0);
                    gpio_set_level(BLUE_LED_PIN, 1);
                }
                break;
            case LED_BEHAVIOR_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(RED_LED_PIN, 1);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(RED_LED_PIN, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(GREEN_LED_PIN, 1);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(GREEN_LED_PIN, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(BLUE_LED_PIN, 1);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(BLUE_LED_PIN, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_FAST_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(RED_LED_PIN, 1);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(RED_LED_PIN, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(GREEN_LED_PIN, 1);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(GREEN_LED_PIN, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(BLUE_LED_PIN, 1);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(BLUE_LED_PIN, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_SLOW_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(RED_LED_PIN, 1);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(RED_LED_PIN, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(GREEN_LED_PIN, 1);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(GREEN_LED_PIN, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(BLUE_LED_PIN, 1);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(BLUE_LED_PIN, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_CYCLE:
                gpio_set_level(RED_LED_PIN, 0);
                gpio_set_level(GREEN_LED_PIN, greenLEDBrightness);
                gpio_set_level(BLUE_LED_PIN, 0);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                gpio_set_level(RED_LED_PIN, 0);
                gpio_set_level(GREEN_LED_PIN, 0);
                gpio_set_level(BLUE_LED_PIN, blueLEDBrightness);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                gpio_set_level(RED_LED_PIN, redLEDBrightness);
                gpio_set_level(GREEN_LED_PIN, 0);
                gpio_set_level(BLUE_LED_PIN, 0);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                break;
        }
        
        // Add a short delay to ensure the task yields control and resets the watchdog
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
