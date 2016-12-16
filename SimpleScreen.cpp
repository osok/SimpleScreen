/**
 * SimpleScreen.h - Library for to simplify the interaction with a LCD Screen.
 * Created by osok
 * github https://github.com/osok/SimpleScreen
 * Released into public domain. * 
 */

#include "SimpleScreen.h"

SimpleScreen::SimpleScreen(NokiaLCD* lcd){
  _lcd = lcd;

  initScreen();
}


void SimpleScreen::initScreen(){
  for (int row = 0; row < ROWS; row++){
    for (int col = 0; col < COLS; col++){
      screen[row][col] = 0x20;
    }
  }
  screen[ROWS][0] = 0x00; // Last char has to remain a null byte
  
}

void SimpleScreen::replaceNull(){
  for (int row = 0; row < ROWS; row++){
    for (int col = 0; col < COLS; col++){
      if(!screen[row][col]){
        screen[row][col] = 0x20;
      }
    }
    screen[ROWS][0] = 0x00; // Last char has to remain a null byte
  }
}
void SimpleScreen::writeString(int row, char* c){
  //TODO: write string to row.  Clear row, then only write on this one row.
  
}

void SimpleScreen::writeCharacter(int row, int col, char c){
  // TODO: add bounds checking
  screen[row][col] = c;
}

void SimpleScreen::paint(){
  replaceNull();
  _lcd->writeString(screen[0]);
}

