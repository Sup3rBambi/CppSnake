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
      body.push_back(std::pair(body.at(body.size() - 1).first - 1, body.at(body.size() - 1).second));
      body.erase(body.begin());
      break;
    case RIGHT:
      body.push_back(std::pair(body.at(body.size() - 1).first + 1, body.at(body.size() - 1).second));
      body.erase(body.begin());
      break;
    case UP:
      body.push_back(std::pair(body.at(body.size() - 1).first, body.at(body.size() - 1).second - 1));
      body.erase(body.begin());
      break;
    case DOWN:
      body.push_back(std::pair(body.at(body.size() - 1).first, body.at(body.size() - 1).second + 1));
      body.erase(body.begin());
      break;
  }
}

void Snake::Eat() {

}