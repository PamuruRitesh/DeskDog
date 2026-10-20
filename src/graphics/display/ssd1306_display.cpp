
#include "ssd1306_display.h"
#include "ssd1306_config.h"

#include <Wire.h>

Ssd1306Display::Ssd1306Display()
    : oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
}

bool Ssd1306Display::begin()
{
    if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        return false;
    }

    oled.clearDisplay();
    oled.display();

    return true;
}

void Ssd1306Display::clear()
{
    oled.clearDisplay();
}

void Ssd1306Display::fill_circle(
    int16_t x,
    int16_t y,
    int16_t radius,
    DisplayColor color
)
{
    uint16_t oled_color =
        (color == DisplayColor::white) ? SSD1306_WHITE : SSD1306_BLACK;

    oled.fillCircle(x, y, radius, oled_color);
}

void Ssd1306Display::show()
{
    oled.display();
}
