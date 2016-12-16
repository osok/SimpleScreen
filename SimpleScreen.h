/**
 * SimpleScreen.h - Library for to simplify the interaction with a LCD Screen.
 * Created by osok
 * github https://github.com/osok/SimpleScreen
 * Released into public domain. * 
 */

#ifndef SimpleScreen_h
#define SimpleScreen_h

#include <NokiaLCD.h>

//TODO: Need to move these to the LCD and pull from it,
//      so that the screen is more dynamic
#define ROWS 6
#define COLS 12

class SimpleScreen{
  private:
    NokiaLCD* _lcd;
    char screen[ROWS+1][COLS];
    
    void replaceNull();
    void initScreen();
    
  public:
   /**
    *  TODO: Need to abstract LCD from NokiaLCD once I add new LCD into the mix
    */
    SimpleScreen(NokiaLCD* lcd);  
    void paint();
    void writeCharacter(int row, int col, char c);
    void writeString(int row, char* c);
};



#endif
