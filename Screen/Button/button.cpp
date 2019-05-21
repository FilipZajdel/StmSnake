#include "button.h"

Button::Button(uint16_t x, uint16_t y, uint16_t width, uint16_t height, string Text){
    
    MyRectangle = new Rectangle(x,y,width, height);
    MyRectangle->SetText(Text, BUTTON_TEXT_COLOR, BUTTON_TEXT_BACK_COLOR);
    
    CbOnPress = NULL;
    CbOnRelease = NULL;
    
    State = RELEASED;
}

Button::Button(uint16_t x, uint16_t y, uint16_t width, uint16_t height, 
                WidgetCallback* CbOnPress, WidgetCallback* CbOnRelease, 
                string Text): CbOnPress(CbOnPress), CbOnRelease(CbOnRelease)  {

    MyRectangle = new Rectangle(x,y,width, height);
    MyRectangle->SetText(Text, BUTTON_TEXT_COLOR, BUTTON_TEXT_BACK_COLOR);
    
    State = RELEASED;
}  

bool Button::CheckRectRange(uint16_t X, uint16_t Y){
    uint16_t RectX = MyRectangle->GetX();
    uint16_t RectY = MyRectangle->GetY();
    uint16_t RectHeight = MyRectangle->GetHeight();
    uint16_t RectWidth = MyRectangle->GetHeight();
    
    return (X>=RectX && X<RectX+RectWidth && Y>=RectY && Y<RectY+RectHeight);
}

void Button::Check(uint16_t X, uint16_t Y){
    
    State = (CheckRectRange(X,Y) ? PRESSED : RELEASED);
    
    switch(State){
        case PRESSED:
            OnPress();
            break;
        case RELEASED:
            OnRelease();
            break;
    }
};         

bool Button::isPressed(uint16_t X, uint16_t Y){
    return !(CheckRectRange(X,Y) ? PRESSED : RELEASED);
} 

void Button::OnPress(){
    
    MyRectangle->SetFillingColor(BUTTON_PUSH_COLOR);
    
    if(NULL != CbOnPress){
        CbOnPress->Execute();
    }
}

void Button::OnRelease(){
    
    MyRectangle->SetFillingColor(BUTTON_RELEASE_COLOR);
    
    if(NULL != CbOnRelease) {
        CbOnRelease->Execute();
    }
}       

Figure *Button::GetFigure(){
    return MyRectangle;
}

Button::~Button(){
    delete MyRectangle;
}