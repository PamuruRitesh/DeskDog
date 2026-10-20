
#include <Arduino.h>

#include "display.h"
#include "ssd1306_display.h"

static Ssd1306Display oled_display;

void init_display()
{
    if (!oled_display.begin())
    {
        while (true)
        {
            delay(1000);
        }
    }
}

void clear_display()
{
    oled_display.clear();
}

void update_display()
{
    oled_display.show();
}

DisplayInterface& get_display()
{
    return oled_display;
}
