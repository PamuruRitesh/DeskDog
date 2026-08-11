#include <Arduino.h>

#include "graphics/display/display.h"
#include "core/dog.h"

void setup()
{
    initDisplay();
}

void loop()
{
    clearDisplay();

    drawDog();

    updateDisplay();

    delay(100);
}
