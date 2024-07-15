#include <chrono>
#include <thread>
#include <iostream>

#include "gameState.h"

GameState::GameState() 
    : width(50), height(10) {
  this->Setup(); 
  this->GameLoop();
}

GameState::~GameState() {
  this->CleanUp();
}

void GameState::Setup() {
  state = SETUP;
}

void GameState::GameLoop() {
  isGameOn = true;
  state = GAME_LOOP;
  while (isGameOn) {
    // Input();
    Display();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  this->CleanUp(); 
}

void GameState::CleanUp() {
  state = CLEAN_UP;
}

void GameState::Input() {
  char input = getchar();
  printf("%c", input);
  switch (input) {
    case 'q': 
      isGameOn = false;
      break;
    case 'i':
      // snake.Up();
      break;
    case 'k':
      // snake.Down();
      break;
    case 'j':
      // snake.Left();
      break;
    case 'l':
      // snake.Right();
      break;
    default: 
      break;
  }
}

void GameState::Display() {
  system("clear");
  char display[width * height];
  std::fill_n(display, width * height, '.');

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", display[y * width + x]);
    }
    printf("\n");
  }
}