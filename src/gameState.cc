#include <chrono>
#include <thread>
#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "gameState.h"
#include "snake.h"

GameState::GameState() 
    : width(50), height(10) {

  system("stty raw"); 
  tInput = std::thread(GameState::GetInput, &input, &isInputNeeded);
  //setting console raw mode
  // struct termios* termios_p;
  // cfmakeraw(termios_p);

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
    // CheckCollisions();
    Display();
    Input();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  this->CleanUp(); 
}

void GameState::CleanUp() {
  state = CLEAN_UP;
  isInputNeeded = false;
  system("stty -raw"); 
}

void GameState::GetInput(char* input, bool* isInputNeeded) {
  while (*isInputNeeded) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cin.read(input, 1);
  }
}

void GameState::Input() {
  // printf("%c", input);
  switch (input) {
    case 'q': 
      isGameOn = false;
      break;
    case 'i':
      snake.Up();
      break;
    case 'k':
      snake.Down();
      break;
    case 'j':
      snake.Left();
      break;
    case 'l':
      snake.Right();
      break;
    default: 
      snake.Move();
      break;
  }
}

void GameState::CheckCollisions() {
  // if (snake.GetPositions().back()) {

  // } else if (snake.GetPositions().back()) {

  // } else if (snake.GetPositions().back()) {

  // } else if (snake.GetPositions().back()) {

  // }
}

void GameState::Display() {
  system("clear");
  char display[width * height];
  std::fill_n(display, width * height, '.');
  for (auto pos : snake.GetPositions()){
    display[pos.second * width + pos.first] = '#';
  }  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", display[y * width + x]);
    }
    printf("\r\n");
  }
}