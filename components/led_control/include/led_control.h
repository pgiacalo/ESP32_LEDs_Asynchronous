#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Define GPIO pins for the RGB LED
#define RED_LED_PIN GPIO_NUM_13
#define GREEN_LED_PIN GPIO_NUM_12
#define BLUE_LED_PIN GPIO_NUM_14

// LED behavior and color enumerations
typedef enum {
    LED_BEHAVIOR_OFF,
    LED_BEHAVIOR_ON,
    LED_BEHAVIOR_BLINK,
    LED_BEHAVIOR_FAST_BLINK,
    LED_BEHAVIOR_SLOW_BLINK,
    LED_BEHAVIOR_CYCLE
} LedBehavior;

typedef enum {
    LED_COLOR_RED,
    LED_COLOR_GREEN,
    LED_COLOR_BLUE
} LedColor;

// Shared variables
extern volatile LedBehavior ledBehavior;
extern volatile LedColor ledColor;

// Function declarations
void initializeLEDs();
void controlLEDs(void *pvParameters);
void setBlinkInterval(int interval);
void setFastBlinkInterval(int interval);
void setSlowBlinkInterval(int interval);
void setCycleInterval(int interval);
void setRedLEDBrightness(int brightness);
void setGreenLEDBrightness(int brightness);
void setBlueLEDBrightness(int brightness);
int getBlinkInterval();
int getFastBlinkInterval();
int getSlowBlinkInterval();
int getCycleInterval();
int getRedLEDBrightness();
int getGreenLEDBrightness();
int getBlueLEDBrightness();

#endif // LED_CONTROL_H
