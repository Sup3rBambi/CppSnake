#ifndef CPPSNAKE_GAMESTATE_H_
#define CPPSNAKE_GAMESTATE_H_
#endif

// #include "snake.h"

enum State {
  SETUP = 0,
  GAME_LOOP,
  CLEAN_UP
};

class GameState {
 public:
  GameState();
  ~GameState();
  
  void Setup();
  void GameLoop();
  void CleanUp();

  void Display();
  void Input();
  
 private:
  State state;
  bool isGameOn;
  int width;
  int height;
  // Snake snake;
};