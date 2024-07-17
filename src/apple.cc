#include "apple.h"
#include "snake.h"

#include <cstdlib>

Apple::Apple(Snake snake) : snake(snake) {
  ChangePos();
}

Apple::~Apple() {

}

void Apple::ChangePos() {
  bool isValidPos = false;
  while (!isValidPos) {
    x = rand() % 50;
    y = rand() % 10;
    isValidPos = true;
    for (auto pos : snake.GetPositions()) {
      if (pos.first == x && pos.second == y)
       isValidPos = false;
    }
  }
}