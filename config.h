#ifndef config_h
#define config_h


/* Includes all default values specified in instruction for this project*/

// Screen
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

// Rectangles
#define RECTANGLE_DEFAULT_FILLING_COLOR LCD_COLOR_BLUE
#define RECTANGLE_DEFAULT_FRAME_COLOR   LCD_COLOR_WHITE
#define RECTANGLE_DEFAULT_TEXT  ""
#define RECTANGLE_DEFAULT_TEXT_COLOR    LCD_COLOR_WHITE
#define RECTANGLE_DEFAULT_TEXT_BACK_COLOR   LCD_COLOR_RED

// Buttons
#define BUTTON_RELEASE_COLOR    LCD_COLOR_GRAY
#define BUTTON_PUSH_COLOR       LCD_COLOR_YELLOW
#define BUTTON_TEXT_COLOR       LCD_COLOR_WHITE
#define BUTTON_TEXT_BACK_COLOR  LCD_COLOR_RED
#define ARROWS_Y            ((uint16_t)279)
#define ARROWS_WIDTH        ((uint16_t)80)
#define ARROWS_HEIGHT       ((uint16_t)40)

// Temporary Defines
#define RECTANGLE_NR    4
#define RECTANGE_WIDTH  80
#define RECTANGE_HEIGHT 80
#define BUTTONS_NR      4

#endif