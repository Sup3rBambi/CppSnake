#include <iostream>

#include "snake.h"

Snake::Snake() {
  body.emplace_back(0, 0);
  currentDirection = RIGHT;
}

Snake::~Snake() {

}

void Snake::Left() {
  if (currentDirection != RIGHT) {
    currentDirection = LEFT;
  }
  Move();
}

void Snake::Right() {
  if (currentDirection != LEFT) {
    currentDirection = RIGHT;
  }
  Move();
}

void Snake::Up() {
  if (currentDirection != DOWN) {
    currentDirection = UP;
  }
  Move();
}

void Snake::Down() {
  if (currentDirection != UP) {
    currentDirection = DOWN;
  }
  Move();
}

void Snake::Move() {
  switch (currentDirection) {
    case LEFT:
      if (body.at(body.size() - 1).first - 1 < 0) 
        isAlive = false;
      body.push_back(std::pair(body.at(body.size() - 1).first - 1, body.at(body.size() - 1).second));
      break;
    case RIGHT:
      if (body.at(body.size() - 1).first + 1 > 49) 
        isAlive = false;
      body.push_back(std::pair(body.at(body.size() - 1).first + 1, body.at(body.size() - 1).second));
      break;
    case UP:
      if (body.at(body.size() - 1).second - 1 < 0) 
        isAlive = false;
      body.push_back(std::pair(body.at(body.size() - 1).first, body.at(body.size() - 1).second - 1));
      break;
    case DOWN:
      if (body.at(body.size() - 1).second + 1 > 9) 
        isAlive = false;
      else 
        body.push_back(std::pair(body.at(body.size() - 1).first, body.at(body.size() - 1).second + 1));
      break;
  }
  if (!fHasEaten)
    body.erase(body.begin());
  fHasEaten = false;
  for (int i = 0; i < body.size() - 1; i++) {
    if (body[i].first == body.back().first && body[i].second == body.back().second)
      isAlive = false;
  }
}
