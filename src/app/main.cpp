#include <Arduino.h>

#include "graphics/display/display.h"
#include "core/dog.h"

void setup()
{
    init_display();
}

void loop()
{
    clear_display();

    draw_dog(get_display());

    update_display();

    delay(100);
}