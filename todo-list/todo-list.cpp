/*
  Author: Matteo Paoli
  Program: Todo list
  Version: 1.1.0

  Description:
  My personal implementation of the most common programming exercise ever.

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 15/08/2023 - last review 22/08/2023
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::string SW_VERSION = "1.1.0";
const std::string SAVE_FILE_NAME = "todo.txt";

std::string getUserInput() {
  std::string userInput;
  std::getline(std::cin, userInput);
  return userInput;
}

std::vector<std::string> readSave() {
  std::vector<std::string> list;
  std::ifstream todoFile(SAVE_FILE_NAME);
  if (todoFile.is_open()) {
    std::string line;
    while (std::getline(todoFile, line)) {
      list.push_back(line);
    }
  }
  else {
    std::cout << "Save file not found, creating..." << std::endl;
    std::ofstream outfile(SAVE_FILE_NAME);
  }
  return list;
}

void save(const std::vector<std::string> &todoList) {
  std::ofstream outfile(SAVE_FILE_NAME);
  if (outfile.is_open()) {
    for (const std::string &item : todoList) {
      outfile << item << std::endl;
    }
  }
  else {
    std::cerr << "Error opening file: " << SAVE_FILE_NAME << std::endl;
  }
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
  save(todoList);
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
    save(todoList);
  } else {
    std::cout << "Invalid index." << std::endl;
  }
}

void editTask(std::vector<std::string> &todoList) {
  if (todoList.empty()) {
    std::cout << "You have no items in your list." << std::endl;
    return;
  }
  printToDoTasks(todoList);
  std::cout << "Which one do you want to edit? ";
  size_t indexToEdit = std::stoul(getUserInput()) - 1;
  if (indexToEdit >= 0 && indexToEdit < todoList.size()) {
    std::cout << "Edit the item" << std::endl;
    todoList[indexToEdit] = getUserInput();
    save(todoList);
  }
}

int main() {
  std::string userInput;
  std::vector<std::string> todoList = readSave();
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
      editTask(todoList);
    } else {
      std::cout << "Invalid input" << std::endl;
    }
  }
  return 0;
}
