#ifndef widgetcallback_h
#define widgetcallback_h

#include "widget.h"

/** @brief Defines base class for callbacks used by widgets */
class WidgetCallback{
public:
    virtual void Execute(void) = 0;    
protected:
    WidgetCallback(Widget *);    
private:
    Widget *MyWidget;
};

#endif
