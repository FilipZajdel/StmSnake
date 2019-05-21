#include "LCD_DISCO_F429ZI.h"
#include "StmSnakeConfig.hpp"
#include "TS_DISCO_F429ZI.h"
#include "button.h"
#include "DiscoScreenConfig.h"
#include "mbed.h"
#include "rectangle.h"

#include <string>
#include <vector>
#include <memory>

#include "Snake/Snake.hpp"
#include "StmScreenManager/StmScreenManager.hpp"

using std::string;
using std::vector;
using std::unique_ptr;

LCD_DISCO_F429ZI LcdScreen;

int main() {
  GameManager* snake = new SnakeManager{std::move(unique_ptr<ScreenManager>{new StmScreenManager{}})};

  LCD_DISCO_F429ZI LcdScreen;
  TS_DISCO_F429ZI TouchScreen;

  BSP_LCD_SetFont(&Font24);
  LcdScreen.Clear(LCD_COLOR_BLACK);
  LcdScreen.SetBackColor(LCD_COLOR_BLACK);
  uint8_t TsStatus =
      TouchScreen.Init(LcdScreen.GetXSize(), LcdScreen.GetYSize());

  Button* ArrowLeft = (new Button{(uint16_t)0, ARROWS_Y, ARROWS_WIDTH,
                                  ARROWS_HEIGHT, string{""}});
  Button* ArrowDown = (new Button{ARROWS_WIDTH, ARROWS_Y, ARROWS_WIDTH,
                                  ARROWS_HEIGHT, string{""}});
  Button* ArrowRight =
      (new Button{(uint16_t)2 * ARROWS_WIDTH, ARROWS_Y, ARROWS_WIDTH - 1,
                  ARROWS_HEIGHT, string{""}});
  Button* ArrowUp = (new Button{ARROWS_WIDTH, ARROWS_Y - ARROWS_HEIGHT,
                                ARROWS_WIDTH, ARROWS_HEIGHT, string{""}});

  Rectangle* ScoreRect = new Rectangle{SCORE_RECT_X_COORD, SCORE_RECT_Y_COORD,
                                       SCORE_RECT_WIDTH, SCORE_RECT_HEIGHT};

  ScoreRect->SetText("SCORE: 0", SCORE_TEXT_COLOUR, SCORE_TEST_BG_COLOUR);
  ScoreRect->SetFillingColor(SCORE_FRAME_COLOUR);
  ScoreRect->SetFrameColor(SCORE_FILLING_COLOUR);

  vector<Widget*> Arrows{ArrowLeft, ArrowDown, ArrowUp, ArrowRight};

  char direction = 'w', intervalCtr = 0;

  while (TS_OK == TsStatus) {
    TS_StateTypeDef TsState;
    uint16_t XCoord = SCREEN_WIDTH + 1, YCoord = SCREEN_HEIGHT + 1;

    TouchScreen.GetState(&TsState);
    if (TsState.TouchDetected) {
      XCoord = TsState.X;
      YCoord = TsState.Y;
    }

    for (vector<Widget*>::iterator ItWidget = Arrows.begin();
         ItWidget != Arrows.end(); ItWidget++) {
      (*ItWidget)->Check(XCoord, YCoord);
      LcdScreen << (*ItWidget)->GetFigure();
    }

    if (ArrowRight->isPressed(XCoord, YCoord)) {
      direction = (direction != SNAKE_LEFT) ? SNAKE_RIGHT : direction;
    } else if (ArrowLeft->isPressed(XCoord, YCoord)) {
      direction = (direction != SNAKE_RIGHT) ? SNAKE_LEFT : direction;
    } else if (ArrowUp->isPressed(XCoord, YCoord)) {
      direction = (direction != SNAKE_DOWN) ? SNAKE_UP : direction;
    } else if (ArrowDown->isPressed(XCoord, YCoord)) {
      direction = (direction != SNAKE_UP) ? SNAKE_DOWN : direction;
    } else {
      direction = direction;
    }

    if (intervalCtr > 8) {
      snake->updateGame(direction);
      vector<GameResult> currentResults{snake->getResults()};
      ScoreRect->SetText(
          "SCORE: " +
              std::to_string((currentResults.back()).getIntResult(POINTS_NAME)),
          SCORE_TEXT_COLOUR, SCORE_TEST_BG_COLOUR);

      LcdScreen << ScoreRect;
      intervalCtr = 0;
    }

    wait(0.02);
    intervalCtr++;
  }
}
