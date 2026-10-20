#ifndef DOG_H
#define DOG_H

#include "graphics/display/display_interface.h"

enum class EyeState
{
    open,
    closed
};

enum class EyeDirection
{
    center,
    left,
    right
};

enum class DogExpression
{
    happy,
    sleepy,
    surprised
};

void draw_dog(
    DisplayInterface& display,
    EyeState eye_state = EyeState::open,
    EyeDirection eye_direction = EyeDirection::center,
    DogExpression expression = DogExpression::happy
);
#endif
