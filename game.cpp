/*
  Author: Matteo Paoli
  Program: Guessing the number
  Version: 1.3.0

  Description:
  A sample game I've created for learning C++

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 14/08/2023 - last review 14/08/2023
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "settings.h"

const std::string MAX_RANGE_CONFIG_KEY = "maxRange";
const std::string ATTEMPTS_CONFIG_KEY = "attempts";
const std::string SW_VERSION = "1.3.0";

bool game_iteration(int randomNumber) {
  int userGuess;
  std::string userInput;
  std::cout << "Guess the number: ";
  std::getline(std::cin, userInput);
  try {
    userGuess = std::stoi(userInput);
  } catch (const std::invalid_argument &e) {
    throw std::runtime_error("Failed to parse user input");
  }
  return userGuess == randomNumber;
}

int main(int argc, char *argv[]) {
  bool debugMode = false;
  bool guessed = false;
  std::map<std::string, int> settings;

  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--debug") {
      debugMode = true;
    }
  }

  try {
    settings = get_settings();
  } catch (const std::exception &e) {
    std::cerr << "Error loading settings: " << e.what() << std::endl;
    return 1;
  }

  std::srand(std::time(0));
  int randomNumber = std::rand() % settings[MAX_RANGE_CONFIG_KEY] + 1;
// Clear the console
#ifdef _WIN32
  system("cls");
#else
  system("clear");  // For Unix-like systems
#endif
  std::cout << "GUESSING NUMBER GAME" << std::endl;
  std::cout << "Developed by Matteo Paoli - v" << SW_VERSION << std::endl;
  if (debugMode) {
    std::cout << "WARNING: DEBUG MODE IS ENABLED" << std::endl;
    std::cout << "DEBUG: randomNumber = " << randomNumber << std::endl;
  }

  for (int i = settings[ATTEMPTS_CONFIG_KEY]; i > 0; i--) {
    std::cout << std::to_string(i) << " attempts left" << std::endl;
    try {
      if (game_iteration(randomNumber)) {
        guessed = true;
        break;
      } else {
        std::cout << "Nice try, but that's not the right number." << std::endl;
      }
    } catch (const std::exception &e) {
      std::cout << "Invalid input: " << e.what() << std::endl;
      i++;
    }
  }
  if (guessed) {
    std::cout << "You guessed! The number was " << randomNumber << std::endl;
  } else {
    std::cout << "The number was " << randomNumber << "." << std::endl;
    std::cout << "You lost the game, try again." << std::endl;
  }
  return 0;
}