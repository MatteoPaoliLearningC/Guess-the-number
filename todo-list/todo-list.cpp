/*
  Author: Matteo Paoli
  Program: Todo list
  Version: 0.3.1

  Description:
  My personal implementation of the most common programming exercise ever.

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 15/08/2023 - last review 20/08/2023
*/
#include <iostream>
#include <string>
#include <vector>

const std::string SW_VERSION = "0.3.1";

std::string getUserInput() {
  std::string userInput;
  std::getline(std::cin, userInput);
  return userInput;
}

void printToDoTasks(const std::vector<std::string> &todoList) {
  for (size_t i = 0; i < todoList.size(); i++) {
    std::cout << i + 1 << ") " << todoList[i] << std::endl;
  }
}

void addTask(std::vector<std::string> &todoList) {
  std::string userInput;
  std::cout << "Enter your activity: ";
  todoList.push_back(getUserInput());
}

void deleteTask(std::vector<std::string> &todoList) {
  if (todoList.empty()) {
    std::cout << "You have no items in your list." << std::endl;
    return;
  }
  printToDoTasks(todoList);
  std::cout << "Which one do you want to delete? ";
  size_t indexToRemove = std::stoul(getUserInput()) - 1;
  if (indexToRemove >= 0 && indexToRemove < todoList.size()) {
    todoList.erase(todoList.begin() + indexToRemove);
  } else {
    std::cout << "Invalid index." << std::endl;
  }
}

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
      printToDoTasks(todoList);
    }
    std::cout << "What do you wanna do? (add / delete / edit)" << std::endl;
    userInput = getUserInput();
    if (userInput == "add") {
      addTask(todoList);
    } else if (userInput == "delete") {
      deleteTask(todoList);
    } else if (userInput == "edit") {
      // TODO
    } else {
      std::cout << "Invalid input" << std::endl;
    }
  }
  return 0;
}
