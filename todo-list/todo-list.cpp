/*
  Author: Matteo Paoli
  Program: Todo list
  Version: 0.3.0

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

const std::string SW_VERSION = "0.3.0";

void printToDoTasks(const std::vector<std::string> &todoList) {
  for (size_t i = 0; i < todoList.size(); i++) {
    std::cout << i + 1 << ") " << todoList[i] << std::endl;
  }
}

void addTask(std::vector<std::string> &todoList) {
  std::string userInput;
  std::cout << "Enter your activity: ";
  std::getline(std::cin, userInput);
  todoList.push_back(userInput);
}

void deleteTask(std::vector<std::string> &todoList) {
  if (todoList.empty()) {
    std::cout << "You have no items in your list." << std::endl;
    return;
  }

  printToDoTasks(todoList);

  size_t indexToRemove;
  std::cout << "Which one do you want to delete? ";
  std::cin >> indexToRemove;
  indexToRemove--;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    std::getline(std::cin, userInput);
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
