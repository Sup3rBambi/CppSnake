#ifndef CPPSNAKE_SNAKE_H_
#define CPPSNAKE_SNAKE_H_
#endif

#include <vector>

class Snake {
 public:
  bool fHasEaten = false;

  Snake();
  ~Snake();
  
  void Left();
  void Right();
  void Up();
  void Down();

  inline std::vector<int, int> GetPositions() { return positions; }
 private:
  std::vector<int, int> positions;
};