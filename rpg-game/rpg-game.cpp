/*
  Author: Matteo Paoli
  Program: RPG GAME
  Version: 0.2.0

  Description:
  A sample game I've created for learning C++

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 22/08/2023 - last review 23/08/2023
*/

#include <iostream>
#include <ncurses.h>
#include "player.h"
#include "enemy.h"
;
const char* SW_VERSION = "0.2.0";

int main() {
  std::string userInput;
  initscr();
  printw("RPG GAME\n");
  printw("Developed by Matteo Paoli - v%s", SW_VERSION);

  refresh();
  getch();
  endwin();

  // std::cout << "Enter your name: ";
  // std::getline(std::cin, userInput);
  // Player player(userInput);
  // Enemy enemy;
  // std::cout << "This is is your player:" << std::endl;
  // std::cout << "NAME: " << player.name() << std::endl;
  // std::cout << "HEALTH: " << player.health() << std::endl;
  // std::cout << "ATTACK: " << player.attack() << std::endl;
  // std::cout << "DEFENSE: " << player.defense() << std::endl;

  // std::cout << ": " << player.defense() << std::endl;
  
}