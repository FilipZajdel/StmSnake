#ifndef button_h
#define button_h

#include "rectangle.h"
#include "LCD_DISCO_F429ZI.h"
#include "DiscoScreenConfig.h"
#include "widget.h"
#include "widgetcallback.h"

#include <string>

using std::string;

/** @brief Button class */
class Button : public Widget{
public:
    Button(){}
    /** @brief Constructs button with given parameters.
     * @param x x - coordinate on the screen
     * @param y y - coordinate on the screen
     * @param width - width of the button
     * @param height - height of the button
     * @param Text - text displayed on the button
     */
    Button(uint16_t x, uint16_t y, uint16_t width, uint16_t height, string Text = RECTANGLE_DEFAULT_TEXT);
    /** @brief Construct button with given parameters.
     * @param x x - coordinate on the screen
     * @param y y - coordinate on the screen
     * @param width - width of the button
     * @param height - height of the button
     * @param Text - text displayed on the 
     * @param CbOnPress - callback on press
     * @param CbOnRelease - callback on release
     */
    Button(uint16_t x, uint16_t y, uint16_t width, uint16_t height, WidgetCallback* CbOnPress, WidgetCallback* CbOnRelease, string Text = RECTANGLE_DEFAULT_TEXT);
    virtual ~Button();
    /** @brief Checks whether button is pressed on not. Invokes appropriate callbacks. */
    virtual void Check(uint16_t X, uint16_t Y);
    /** @brief Returns true if pressed, false otherwise */
    virtual bool isPressed(uint16_t X, uint16_t Y);
    /** @brief Returns the figure which button consists of */
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