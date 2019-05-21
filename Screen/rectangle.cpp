#include "rectangle.h"
#include "LCD_DISCO_F429ZI.h"

Rectangle::Rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t FillingColor, uint32_t FrameColor, string Text, uint32_t TextColor):
    x(x), y(y), width(width), height(height), FillingColor(FillingColor), FrameColor(FrameColor), TextColor(TextColor), Text(Text){}

LCD_DISCO_F429ZI & Rectangle::Draw(LCD_DISCO_F429ZI &lcd){
    lcd.SetTextColor(FrameColor);
    lcd.DrawRect(x,y,width, height);
    
    lcd.SetTextColor(FillingColor);
    lcd.FillRect(x+1,y+1,width-1,height-1);
    
    DisplayString(lcd);
    
    return lcd;
}

void Rectangle::SetFillingColor(uint32_t Color){
    this->FillingColor = Color;
}

void Rectangle::SetFrameColor(uint32_t Color){
    this->FrameColor = Color;
}

void Rectangle::SetText(string Text, uint32_t TextColor, uint32_t TextBackColor){
    this->Text = Text;
    this->TextColor = TextColor;
    this->TextBackColor = TextBackColor;
}

void Rectangle::DisplayString(LCD_DISCO_F429ZI &lcd){
    
    uint8_t *uText = new uint8_t [Text.length()+1];
    sprintf((char*)uText, "%s", Text.c_str());
    lcd.SetBackColor(TextBackColor);
    lcd.SetTextColor(TextColor);
    lcd.DisplayStringAt(x, y, uText, LEFT_MODE);   
    
    delete []uText; 
}

uint16_t Rectangle::GetX(){
    return x;
}
uint16_t Rectangle::GetY(){
    return y;
}
uint16_t Rectangle::GetWidth(){
    return width;
}
uint16_t Rectangle::GetHeight(){
    return height;
}