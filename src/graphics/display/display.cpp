#include "display.h"
#include "config.h"

#include <Wire.h>

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

void initDisplay()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        while (true)
        {
        }
    }

    display.clearDisplay();
    display.display();
}

void clearDisplay()
{
    display.clearDisplay();
}

void updateDisplay()
{
    display.display();
}