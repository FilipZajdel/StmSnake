#ifndef widgetcallback_h
#define widgetcallback_h

#include "widget.h"

class WidgetCallback{
public:
    virtual void Execute(void) = 0;    
protected:
    WidgetCallback(Widget *);    
private:
    Widget *MyWidget;
};


#endif