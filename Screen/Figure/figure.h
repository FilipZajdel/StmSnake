#ifndef figure_h
#define figure_h

#include "LCD_DISCO_F429ZI.h"
#include <string>

/** @brief Base class for shape-like objects */
class Figure {
 public:
  /** @brief Draws the figure to the screen */
  virtual LCD_DISCO_F429ZI& Draw(LCD_DISCO_F429ZI&) = 0;
  /** @brief Enables to set text to the figure */
  virtual void SetText(std::string Text,
                       uint32_t TextColor,
                       uint32_t TextBackground) = 0;
  /** @brief Overloaded stream operator for convenient displaying objects */
  friend LCD_DISCO_F429ZI& operator<<(LCD_DISCO_F429ZI& lcd, Figure* figure);
};

#endif