/*
  Author: Matteo Paoli
  Program: Guessing the number
  Version: 0.1.0

  Description:
  A sample game I've created for learning C++

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 22/08/2023 - last review 22/08/2023
*/

#include <string>
#include <iostream>
#include "player.h"

const std::string SW_VERSION = "0.1.0";

int main() {
  std::string userInput;

  std::cout << "RPG GAME" << std::endl;
  std::cout << "Developed by Matteo Paoli - v" << SW_VERSION << std::endl;

  std::cout << "Enter your name: ";
  std::getline(std::cin, userInput);
  Player player(userInput);
  std::cout << "This is is your player:" << std::endl;
  std::cout << "NAME: " << player.name() << std::endl;
  std::cout << "HEALTH: " << player.health() << std::endl;
  std::cout << "ATTACK: " << player.attack() << std::endl;
  std::cout << "DEFENSE: " << player.defense() << std::endl;
}