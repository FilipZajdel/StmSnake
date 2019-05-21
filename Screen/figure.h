#ifndef figure_h
#define figure_h

#include "LCD_DISCO_F429ZI.h"
#include <string>

class Figure {
public:
    virtual LCD_DISCO_F429ZI &Draw(LCD_DISCO_F429ZI &)=0;    
    virtual void SetText(std::string Text, uint32_t TextColor, uint32_t TextBackground) = 0;
    friend LCD_DISCO_F429ZI & operator <<(LCD_DISCO_F429ZI &lcd, Figure* figure);
};



#endif