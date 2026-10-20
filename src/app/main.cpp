
#include <Arduino.h>

#include "graphics/display/display.h"
#include "core/dog.h"

constexpr unsigned long BLINK_INTERVAL_MS = 3000;
constexpr unsigned long BLINK_DURATION_MS = 200;
constexpr unsigned long LOOK_INTERVAL_MS = 1500;
constexpr unsigned long EXPRESSION_INTERVAL_MS = 5000;

unsigned long last_blink_time = 0;
unsigned long blink_start_time = 0;
unsigned long last_look_time = 0;
unsigned long last_expression_time = 0;

bool is_blinking = false;

EyeDirection eye_direction = EyeDirection::center;
DogExpression expression = DogExpression::happy;

void setup()
{
    init_display();
}

void loop()
{
    unsigned long current_time = millis();

    // Start a blink after the interval.
    if (!is_blinking &&
        current_time - last_blink_time >= BLINK_INTERVAL_MS)
    {
        is_blinking = true;
        blink_start_time = current_time;
    }

    // End the blink after its duration.
    if (is_blinking &&
        current_time - blink_start_time >= BLINK_DURATION_MS)
    {
        is_blinking = false;
        last_blink_time = current_time;
    }

    // Change gaze direction every 1.5 seconds.
    if (current_time - last_look_time >= LOOK_INTERVAL_MS)
    {
        last_look_time = current_time;

        if (eye_direction == EyeDirection::center)
        {
            eye_direction = EyeDirection::left;
        }
        else if (eye_direction == EyeDirection::left)
        {
            eye_direction = EyeDirection::right;
        }
        else
        {
            eye_direction = EyeDirection::center;
        }
    }

    // Change expression every 5 seconds.
    if (current_time - last_expression_time >=
        EXPRESSION_INTERVAL_MS)
    {
        last_expression_time = current_time;

        if (expression == DogExpression::happy)
        {
            expression = DogExpression::sleepy;
        }
        else if (expression == DogExpression::sleepy)
        {
            expression = DogExpression::surprised;
        }
        else
        {
            expression = DogExpression::happy;
        }
    }

    clear_display();

    EyeState eye_state = is_blinking
        ? EyeState::closed
        : EyeState::open;

    draw_dog(get_display(), eye_state, eye_direction, expression);

    update_display();

    delay(10);
}
