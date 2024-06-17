#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Define GPIO pins for the RGB LED
#define RED_LED_PIN GPIO_NUM_13
#define GREEN_LED_PIN GPIO_NUM_12
#define BLUE_LED_PIN GPIO_NUM_14

// Enumerations for LED behavior and color
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

// Function prototypes
void controlLEDs(void *pvParameters);
void initializeLEDs();
void resetLEDs();

// Getter and setter functions for the intervals and brightness
int getBlinkInterval();
int getFastBlinkInterval();
int getSlowBlinkInterval();
int getCycleInterval();

void setBlinkInterval(int interval);
void setFastBlinkInterval(int interval);
void setSlowBlinkInterval(int interval);
void setCycleInterval(int interval);

int getRedLEDBrightness();
int getGreenLEDBrightness();
int getBlueLEDBrightness();

void setRedLEDBrightness(int brightness);
void setGreenLEDBrightness(int brightness);
void setBlueLEDBrightness(int brightness);

#endif // LED_CONTROL_H
