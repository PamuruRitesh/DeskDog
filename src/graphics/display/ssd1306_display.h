
#ifndef SSD1306_DISPLAY_H
#define SSD1306_DISPLAY_H

#include <Adafruit_SSD1306.h>
#include "display_interface.h"

class Ssd1306Display : public DisplayInterface
{
public:
    Ssd1306Display();

    bool begin();

    void clear() override;

    void fill_circle(
        int16_t x,
        int16_t y,
        int16_t radius,
        DisplayColor color
    ) override;

    void draw_circle(
        int16_t x,
        int16_t y,
        int16_t radius,
        DisplayColor color
    ) override;

    void draw_line(
        int16_t x1,
        int16_t y1,
        int16_t x2,
        int16_t y2,
        DisplayColor color
    ) override;

    void show() override;

private:
    Adafruit_SSD1306 oled;
};

#endif
