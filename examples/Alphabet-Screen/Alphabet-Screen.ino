#include "SimpleScreen.h"

#define PIN_LCD 7


NokiaLCD lcd(PIN_LCD);
SimpleScreen screen(&lcd);

void setup(void)
{
  screen.paint();
}

void loop(void)
{
  char c = 'A';
  for (int row = 0; row < ROWS; row++){
    c = 'A';
    for (int col = 0; col < COLS; col++){
      screen.writeCharacter(row, col, c++);
      screen.paint();
      delay(250);
    }
  }
  
}


