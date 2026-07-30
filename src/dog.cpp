#include "dog.h"
#include "display.h"

void drawDog()
{
    // Left Eye
    display.fillCircle(40, 28, 6, SSD1306_WHITE);

    // Right Eye
    display.fillCircle(88, 28, 6, SSD1306_WHITE);

    // Nose
    display.fillCircle(64, 42, 3, SSD1306_WHITE);
}