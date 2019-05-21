#ifndef widget_h
#define widget_h
#include "figure.h"

class Widget{
public:
    virtual Figure* GetFigure() = 0;
    virtual void Check(uint16_t , uint16_t) = 0;
};


#endif