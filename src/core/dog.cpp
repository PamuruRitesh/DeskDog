#include "dog.h"

void draw_dog(DisplayInterface& display)
{
    // Left eye
    display.fill_circle(40, 28, 6, DisplayColor::white);

    // Right eye
    display.fill_circle(88, 28, 6, DisplayColor::white);

    // Nose
    display.fill_circle(64, 42, 3, DisplayColor::white);
}