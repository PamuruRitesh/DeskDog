#include <Arduino.h>

#include "display.h"
#include "dog.h"

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