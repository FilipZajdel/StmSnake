#ifndef widget_h
#define widget_h
#include "figure.h"

/** @brief Interface for Widget */
class Widget{
public:
    virtual ~Widget(){};
    virtual Figure* GetFigure() = 0;
    virtual void Check(uint16_t , uint16_t) = 0;
};


#endif