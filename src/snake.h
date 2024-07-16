#pragma once

#ifndef CPPSNAKE_SNAKE_H_
#define CPPSNAKE_SNAKE_H_
#endif

#include <vector>

enum Direction {
  LEFT = 0,
  RIGHT,
  UP,
  DOWN
};

class Snake {
 public:
  bool fHasEaten = false;

  Snake();
  ~Snake();
  
  void Left();
  void Right();
  void Up();
  void Down();
  void Move();
  void Eat();

  inline std::vector<std::pair<int, int>> GetPositions() { return body; }
 private:
  std::vector<std::pair<int, int>> body;
  Direction currentDirection;
};