
#include "dog.h"

void draw_dog(
    DisplayInterface& display,
    EyeState eye_state,
    EyeDirection eye_direction,
    DogExpression expression
)
{
    

    if (eye_state == EyeState::closed)
    {
        // Blinking takes priority over every expression.
        display.draw_line(34, 28, 46, 28, DisplayColor::white);
        display.draw_line(82, 28, 94, 28, DisplayColor::white);
    }
    else if (expression == DogExpression::sleepy)
    {
        // Half-closed sleepy eyes.
        display.draw_line(34, 27, 46, 29, DisplayColor::white);
        display.draw_line(82, 29, 94, 27, DisplayColor::white);
    }
    else
    {
        int16_t pupil_offset = 0;

        if (eye_direction == EyeDirection::left)
        {
            pupil_offset = -2;
        }
        else if (eye_direction == EyeDirection::right)
        {
            pupil_offset = 2;
        }

        // Fixed eye outlines.
        display.draw_circle(40, 28, 7, DisplayColor::white);
        display.draw_circle(88, 28, 7, DisplayColor::white);

        // Dark eye interiors.
        display.fill_circle(40, 28, 6, DisplayColor::black);
        display.fill_circle(88, 28, 6, DisplayColor::black);

        // Moving pupils.
        display.fill_circle(
            40 + pupil_offset, 28, 3, DisplayColor::white
        );
        display.fill_circle(
            88 + pupil_offset, 28, 3, DisplayColor::white
        );
    }



    // Nose
    display.fill_circle(64, 42, 3, DisplayColor::white);

    // Smile

    // Draw the mouth based on the selected expression.
    if (expression == DogExpression::happy)
    {
        // Happy smile
        display.draw_line(52, 46, 57, 50, DisplayColor::white);
        display.draw_line(57, 50, 64, 52, DisplayColor::white);
        display.draw_line(64, 52, 71, 50, DisplayColor::white);
        display.draw_line(71, 50, 76, 46, DisplayColor::white);
    }
    else if (expression == DogExpression::sleepy)
    {
        // Relaxed, straight mouth
        display.draw_line(57, 49, 71, 49, DisplayColor::white);
    }
    else if (expression == DogExpression::surprised)
    {
        // Small open mouth
        display.draw_circle(64, 50, 3, DisplayColor::white);
    }

}
