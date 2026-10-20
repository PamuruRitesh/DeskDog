
#include <unity.h>

#include "core/dog.h"

struct Circle
{
    int16_t x;
    int16_t y;
    int16_t radius;
    DisplayColor color;
};

struct Line
{
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
    DisplayColor color;
};

class MockDisplay : public DisplayInterface
{
public:
    Circle circles[10];
    int circle_count = 0;

    Line lines[10];
    int line_count = 0;

    void clear() override
    {
    }

    void fill_circle(
        int16_t x,
        int16_t y,
        int16_t radius,
        DisplayColor color
    ) override
    {
        if (circle_count < 10)
        {
            circles[circle_count] = {x, y, radius, color};
            circle_count++;
        }
    }

    void draw_circle(
        int16_t x,
        int16_t y,
        int16_t radius,
        DisplayColor color
    ) override
    {
        if (circle_count < 10)
        {
            circles[circle_count] = {x, y, radius, color};
            circle_count++;
        }
    }

    void draw_line(
        int16_t x1,
        int16_t y1,
        int16_t x2,
        int16_t y2,
        DisplayColor color
    ) override
    {
        if (line_count < 10)
        {
            lines[line_count] = {x1, y1, x2, y2, color};
            line_count++;
        }
    }

    void show() override
    {
    }
};

void setUp()
{
}

void tearDown()
{
}

void test_open_eyes_draw_fixed_outlines_and_pupils()
{
    MockDisplay mock_display;

    draw_dog(
        mock_display,
        EyeState::open,
        EyeDirection::center
    );

    // Two outlines, two dark interiors, two pupils, and one nose.
    TEST_ASSERT_EQUAL_INT(7, mock_display.circle_count);

    // The smile consists of four line segments.
    TEST_ASSERT_EQUAL_INT(4, mock_display.line_count);

    // Left eye outline stays fixed.
    TEST_ASSERT_EQUAL_INT(40, mock_display.circles[0].x);
    TEST_ASSERT_EQUAL_INT(28, mock_display.circles[0].y);
    TEST_ASSERT_EQUAL_INT(7, mock_display.circles[0].radius);
    TEST_ASSERT_EQUAL_INT(
        DisplayColor::white,
        mock_display.circles[0].color
    );

    // Right eye outline stays fixed.
    TEST_ASSERT_EQUAL_INT(88, mock_display.circles[1].x);
    TEST_ASSERT_EQUAL_INT(28, mock_display.circles[1].y);
    TEST_ASSERT_EQUAL_INT(7, mock_display.circles[1].radius);
    TEST_ASSERT_EQUAL_INT(
        DisplayColor::white,
        mock_display.circles[1].color
    );
}

void test_closed_eyes_draw_two_eye_lines()
{
    MockDisplay mock_display;

    draw_dog(mock_display, EyeState::closed);

    // Only the nose is drawn as a circle when eyes are closed.
    TEST_ASSERT_EQUAL_INT(1, mock_display.circle_count);

    // Two closed-eye lines and four smile segments.
    TEST_ASSERT_EQUAL_INT(6, mock_display.line_count);

    // Left closed eye.
    TEST_ASSERT_EQUAL_INT(34, mock_display.lines[0].x1);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[0].y1);
    TEST_ASSERT_EQUAL_INT(46, mock_display.lines[0].x2);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[0].y2);

    // Right closed eye.
    TEST_ASSERT_EQUAL_INT(82, mock_display.lines[1].x1);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[1].y1);
    TEST_ASSERT_EQUAL_INT(94, mock_display.lines[1].x2);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[1].y2);
}


void test_pupils_move_but_eye_outlines_stay_fixed()
{
    MockDisplay left_display;
    MockDisplay right_display;

    draw_dog(left_display, EyeState::open, EyeDirection::left);
    draw_dog(right_display, EyeState::open, EyeDirection::right);

    // The left and right eye outlines must stay at the same positions.
    TEST_ASSERT_EQUAL_INT(
        left_display.circles[0].x,
        right_display.circles[0].x
    );
    TEST_ASSERT_EQUAL_INT(
        left_display.circles[1].x,
        right_display.circles[1].x
    );

    // Left gaze moves the pupils two pixels left.
    TEST_ASSERT_EQUAL_INT(38, left_display.circles[4].x);
    TEST_ASSERT_EQUAL_INT(86, left_display.circles[5].x);

    // Right gaze moves the pupils two pixels right.
    TEST_ASSERT_EQUAL_INT(42, right_display.circles[4].x);
    TEST_ASSERT_EQUAL_INT(90, right_display.circles[5].x);
}


void test_sleepy_expression_can_still_blink()
{
    MockDisplay mock_display;

    draw_dog(
        mock_display,
        EyeState::closed,
        EyeDirection::center,
        DogExpression::sleepy
    );

    // Only the nose is drawn as a circle.
    TEST_ASSERT_EQUAL_INT(1, mock_display.circle_count);

    // Two closed-eye lines and one straight sleepy mouth.
    TEST_ASSERT_EQUAL_INT(3, mock_display.line_count);

    // Verify the left eye is fully closed.
    TEST_ASSERT_EQUAL_INT(34, mock_display.lines[0].x1);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[0].y1);
    TEST_ASSERT_EQUAL_INT(46, mock_display.lines[0].x2);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[0].y2);

    // Verify the right eye is fully closed.
    TEST_ASSERT_EQUAL_INT(82, mock_display.lines[1].x1);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[1].y1);
    TEST_ASSERT_EQUAL_INT(94, mock_display.lines[1].x2);
    TEST_ASSERT_EQUAL_INT(28, mock_display.lines[1].y2);
}



void test_sleepy_expression_draws_straight_mouth()
{
    MockDisplay mock_display;

    draw_dog(
        mock_display,
        EyeState::open,
        EyeDirection::center,
        DogExpression::sleepy
    );

    // Sleepy eyes replace the normal eye circles.
    // Only the nose and round mouth? No: sleepy mouth is a straight line.
    TEST_ASSERT_EQUAL_INT(1, mock_display.circle_count);

    // Two sleepy eye lines and one straight mouth line.
    TEST_ASSERT_EQUAL_INT(3, mock_display.line_count);

    // Check the straight mouth.
    TEST_ASSERT_EQUAL_INT(57, mock_display.lines[2].x1);
    TEST_ASSERT_EQUAL_INT(49, mock_display.lines[2].y1);
    TEST_ASSERT_EQUAL_INT(71, mock_display.lines[2].x2);
    TEST_ASSERT_EQUAL_INT(49, mock_display.lines[2].y2);
}


void test_surprised_expression_draws_round_mouth()
{
    MockDisplay mock_display;

    draw_dog(
        mock_display,
        EyeState::open,
        EyeDirection::center,
        DogExpression::surprised
    );

    // Seven eye and nose circles, plus the circular mouth.
    TEST_ASSERT_EQUAL_INT(8, mock_display.circle_count);

    // No smile lines for the surprised expression.
    TEST_ASSERT_EQUAL_INT(0, mock_display.line_count);
}


int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_open_eyes_draw_fixed_outlines_and_pupils);
    RUN_TEST(test_pupils_move_but_eye_outlines_stay_fixed);
    RUN_TEST(test_sleepy_expression_can_still_blink);
    RUN_TEST(test_closed_eyes_draw_two_eye_lines);
    RUN_TEST(test_sleepy_expression_draws_straight_mouth);
    RUN_TEST(test_surprised_expression_draws_round_mouth);

    return UNITY_END();
}
