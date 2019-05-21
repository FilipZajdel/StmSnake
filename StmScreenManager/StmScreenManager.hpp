#pragma once

#include "LCD_DISCO_F429ZI.h"
#include "figure.h"
#include "../SnakeCore/Snake/Snake.hpp"

extern LCD_DISCO_F429ZI LcdScreen; 

class StmScreenManager : public ScreenManager {
 public:
  StmScreenManager();
  virtual void updateScreen(char map[MAP_SIZE][MAP_SIZE]);

 private:
  vector<vector<Figure*>> figures;
};