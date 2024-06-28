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
static int cycleInterval = 1000; // Cycle through 3 colors interval in milliseconds

// LED pin variables
static gpio_num_t redLEDPin = GPIO_NUM_13;
static gpio_num_t greenLEDPin = GPIO_NUM_12;
static gpio_num_t blueLEDPin = GPIO_NUM_14;

void initializeLEDs() {
    gpio_reset_pin(redLEDPin);
    gpio_reset_pin(greenLEDPin);
    gpio_reset_pin(blueLEDPin);
    
    gpio_set_direction(redLEDPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(greenLEDPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(blueLEDPin, GPIO_MODE_OUTPUT);
    resetLEDs();
}

void resetLEDs() {
    gpio_set_level(redLEDPin, 0);
    gpio_set_level(greenLEDPin, 0);
    gpio_set_level(blueLEDPin, 0);
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
                resetLEDs();
                break;
            case LED_BEHAVIOR_ON:
                resetLEDs();
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(redLEDPin, 1);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(greenLEDPin, 1);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(blueLEDPin, 1);
                }
                break;
            case LED_BEHAVIOR_BLINK:
                resetLEDs();
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(redLEDPin, 1);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(redLEDPin, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(greenLEDPin, 1);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(greenLEDPin, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(blueLEDPin, 1);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(blueLEDPin, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_FAST_BLINK:
                resetLEDs();
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(redLEDPin, 1);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(redLEDPin, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(greenLEDPin, 1);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(greenLEDPin, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(blueLEDPin, 1);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(blueLEDPin, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_SLOW_BLINK:
                resetLEDs();
                if (ledColor == LED_COLOR_RED) {
                    gpio_set_level(redLEDPin, 1);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(redLEDPin, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    gpio_set_level(greenLEDPin, 1);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(greenLEDPin, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    gpio_set_level(blueLEDPin, 1);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    gpio_set_level(blueLEDPin, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_CYCLE:
                resetLEDs();
                gpio_set_level(redLEDPin, 1);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                resetLEDs();
                gpio_set_level(greenLEDPin, 1);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                resetLEDs();
                gpio_set_level(blueLEDPin, 1);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                break;
        }
        
        // Add a short delay to ensure the task yields control and resets the watchdog
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

gpio_num_t getRedLEDPin() {
    return redLEDPin;
}

gpio_num_t getGreenLEDPin() {
    return greenLEDPin;
}

gpio_num_t getBlueLEDPin() {
    return blueLEDPin;
}

void setRedLEDPin(gpio_num_t pin) {
    redLEDPin = pin;
}

void setGreenLEDPin(gpio_num_t pin) {
    greenLEDPin = pin;
}

void setBlueLEDPin(gpio_num_t pin) {
    blueLEDPin = pin;
}
