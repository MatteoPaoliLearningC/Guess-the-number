/*
  Author: Matteo Paoli
  Program: Guessing the number
  Version: 1.0
  
  Description:
  A sample game I've created for learning C++

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 14/08/2023 - last review 14/08/2023
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdexcept>

int main() {
  std::srand(std::time(0));
  std::string userInput;
  bool guessed = false;
  int randomNumber = std::rand() % 10 + 1;
  
  while (!guessed) {
    std::cout << "Guess the number: ";
    std::getline(std::cin, userInput);
    int userGuess;
    try {
      userGuess = std::stoi(userInput);
    }
    catch (const std::invalid_argument& e) {
      std::cout << "Invalid input: " << e.what() << std::endl;
      continue;
    }
    if (userGuess == randomNumber) {
      guessed = true;
      std::cout << "You guessed! The number was " << randomNumber << std::endl;
    }
    else {
      std::cout << "Nice try, but that's not the right number." << std::endl;
    }
  }
  return 0;
}
