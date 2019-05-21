#ifndef rect_h
#define rect_h

#include "mbed.h"
#include "figure.h"
#include "LCD_DISCO_F429ZI.h"
#include "DiscoScreenConfig.h"
#include <string>

using std::string;

/** @brief Defines Rectangle features */
class Rectangle : public Figure {
public:
    /** @brief Constructs rectangle with given parameters.
     * @param x x on screen
     * @param y y on screen
     * @param width width
     * @param height height
     * @param FillingColor filling color of rectangle
     * @param FrameColor frame color of rectangle
     * @param Text text on rectangle
     * @param TextColor color of rectangle's text
     */
    Rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t FillingColor = RECTANGLE_DEFAULT_FILLING_COLOR, uint32_t FrameColor = RECTANGLE_DEFAULT_FRAME_COLOR,
              string Text = RECTANGLE_DEFAULT_TEXT, uint32_t TextColor = RECTANGLE_DEFAULT_TEXT_COLOR);
    /** @brief Draws rectangle to the screen */
    virtual LCD_DISCO_F429ZI & Draw(LCD_DISCO_F429ZI &);
    virtual void SetFillingColor(uint32_t Color);
    virtual void SetFrameColor(uint32_t Color);
    virtual void SetText(string RectangleText, uint32_t TextColor, uint32_t TextBackgroundColor);
    virtual ~Rectangle(){};
    uint16_t GetX();
    uint16_t GetY();
    uint16_t GetWidth();
    uint16_t GetHeight();

private:
    uint16_t x, y, width, height;    
    uint32_t FillingColor, FrameColor, TextColor, TextBackColor;
    string Text;
    
    void DisplayString(LCD_DISCO_F429ZI &lcd);
};


#endif 
