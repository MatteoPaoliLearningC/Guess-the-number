/*
  Author: Matteo Paoli
  Program: Guessing the number
  Version: 1.2.1

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
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

std::map<std::string, int> get_settings() {
  std::ifstream settingsFile("settings.cfg");
  std::map<std::string, int> settings;
  if (settingsFile.is_open()) {
    std::string line;
    while (std::getline(settingsFile, line)) {
      size_t pos = line.find('=');
      if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        int value = std::stoi(line.substr(pos + 1));
        settings[key] = value;
      }
    }
    return settings;
  } else {
    throw std::runtime_error("Failed to open the file.");
  }
}

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

int main() {
  std::map<std::string, int> settings;
  try {
    settings = get_settings();
  } catch (const std::exception &e) {
    std::cerr << "Error loading settings: " << e.what() << std::endl;
    return 1;
  }
  std::srand(std::time(0));

  bool guessed = false;
  int randomNumber = std::rand() % settings["maxRange"] + 1;

  for (int i = settings["attempts"]; i > 0; i--) {
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