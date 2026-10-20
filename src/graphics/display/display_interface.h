#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#include <stdint.h>

enum class DisplayColor : uint8_t
{
    black,
    white
};

class DisplayInterface
{
public:
    virtual ~DisplayInterface() = default;

    virtual void clear() = 0;

    virtual void fill_circle(
        int16_t x,
        int16_t y,
        int16_t radius,
        DisplayColor color
    ) = 0;

    virtual void show() = 0;
};

#endif