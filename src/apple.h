#pragma once

#ifndef CPPSNAKE_APPLE_H_
#define CPPSNAKE_APPLE_H_
#endif

#include "snake.h"

class Apple {
 public:
  Apple(Snake snake);
  ~Apple();

  void ChangePos();
  inline int GetX() { return x; }
  inline int GetY() { return y; }
 private:
  Snake snake;
  int x;
  int y; 
};