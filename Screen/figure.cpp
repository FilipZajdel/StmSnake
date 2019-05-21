#include "figure.h"


LCD_DISCO_F429ZI &operator <<(LCD_DISCO_F429ZI &lcd, Figure* figure){
    return figure->Draw(lcd);
}