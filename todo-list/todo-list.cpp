/*
  Author: Matteo Paoli
  Program: Todo list
  Version: 0.2.0

  Description:
  My personal implementation of the most common programming exercise ever.

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 15/08/2023 - last review 16/08/2023
*/
#include <iostream>
#include <string>
#include <vector>

const std::string SW_VERSION = "0.1.0";

int main() {
  std::string userInput;
  std::vector<std::string> todoList;
  std::cout << "TO-DO LIST" << std::endl;
  std::cout << "Developed by Matteo Paoli - v" << SW_VERSION << std::endl;
  std::cout << "\n";
  while (true) {
    if (todoList.empty()) {
      std::cout << "Your to-do list is empty" << std::endl;
    } else {
      std::cout << "Here is your current to-do list" << std::endl;
      
    }
    std::cout << "Do you wanna add a new item?" << std::endl;
    std::cout << "Answer (y/n): ";
    std::getline(std::cin, userInput);
    if (userInput == "y") {
      std::cout << "Enter your activity: ";
      std::getline(std::cin, userInput);
      todoList.push_back(userInput);
    } else {
      std::cout << "Bye." << std::endl;
      break;
    }
  }
  return 0;
}