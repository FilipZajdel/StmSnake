#include "StmScreenManager.hpp"
#include "rectangle.h"
#include "StmSnakeConfig.hpp"

#include <vector>

StmScreenManager::StmScreenManager() {
  for (int8_t rowCtr = 0; rowCtr < MAP_SIZE; rowCtr++) {
    figures.push_back(vector<Figure*>{});

    for (int8_t colCtr = 0; colCtr < MAP_SIZE; colCtr++) {
      figures[rowCtr].push_back(new Rectangle{
          SNAKE_MAP_OFFSET_X + rowCtr * SNAKE_PART_SIZE_XY, SNAKE_MAP_OFFSET_Y + colCtr * SNAKE_PART_SIZE_XY,
          SNAKE_PART_SIZE_XY, SNAKE_PART_SIZE_XY});
    }
  }
}

void StmScreenManager::updateScreen(char map[MAP_SIZE][MAP_SIZE]) {
  for (int8_t rowCtr = 0; rowCtr < MAP_SIZE; rowCtr++) {
    for (int8_t colCtr = 0; colCtr < MAP_SIZE; colCtr++) {
      Rectangle* rectangle = (Rectangle*)figures[rowCtr][colCtr];
      switch (map[rowCtr][colCtr]) {
        case GamePart::NONE:
          rectangle->SetFillingColor(NONE_COLOUR);
          break;
        case GamePart::SNAKE_PART:
          rectangle->SetFillingColor(SNAKE_PART_COLOUR);
          break;
        case GamePart::SNAKE_MEAL:
          rectangle->SetFillingColor(SNAKE_MEAL_COLOUR);
          break;
        case GamePart::SNAKE_TRAP:
          rectangle->SetFillingColor(SNAKE_TRAP_COLOUR);
          break;
        case GamePart::MEAL_EATEN:
          rectangle->SetFillingColor(MEAL_EATEN_COLOUR);
          break;
        case GamePart::TRAP_BROKEN:
          rectangle->SetFillingColor(TRAP_BROKEN_COLOUR);
          break;
        case GamePart::WALL:
          rectangle->SetFillingColor(WALL_COLOUR);
          break;
      }
      LcdScreen << figures[rowCtr][colCtr];
    }
  }
}