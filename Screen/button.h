#ifndef button_h
#define button_h

// #include "mbed.h"
#include "rectangle.h"
#include "LCD_DISCO_F429ZI.h"
#include "config.h"
#include "widget.h"
#include "widgetcallback.h"
#include <string>

class Button : public Widget{
public:
    Button(){}
    Button(uint16_t x, uint16_t y, uint16_t width, uint16_t height, string Text = RECTANGLE_DEFAULT_TEXT);
    Button(uint16_t x, uint16_t y, uint16_t width, uint16_t height, WidgetCallback* CbOnPress, WidgetCallback* CbOnRelease, string Text = RECTANGLE_DEFAULT_TEXT);
    virtual ~Button(){};
    virtual void Check(uint16_t X, uint16_t Y);
    virtual bool isPressed(uint16_t X, uint16_t Y);
    virtual Figure *GetFigure();   // Temporary Solution
    
private:
    enum {PRESSED, RELEASED};
    uint16_t State;
    Rectangle* MyRectangle;
    WidgetCallback* CbOnPress;
    WidgetCallback* CbOnRelease;
    
    void OnPress();
    void OnRelease();    
    bool CheckRectRange(uint16_t x, uint16_t y);
};




#endif