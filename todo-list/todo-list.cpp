/*
  Author: Matteo Paoli
  Program: Todo list
  Version: 2.0.0

  Description:
  My personal implementation of the most common programming exercise ever.

  Usage:
  [Instructions on how to use the program.]

  Notes:
  [Any additional notes or information about the program.]

  Date: 15/08/2023 - last review 22/08/2023
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string SW_VERSION = "2.0.0";
const std::string SAVE_FILE_NAME = "todo.txt";

class TodoList {
 public:
  TodoList(const std::string &file_name): file_name(file_name) {
    std::ifstream todoFile(file_name);
    if (todoFile.is_open()) {
      std::string line;
      while (std::getline(todoFile, line)) {
        tasks.push_back(line);
      }
      todoFile.close();
    } else {
      std::cout << "Save file not found, creating..." << std::endl;
      std::ofstream outfile(file_name);
    }
  }

  void add(const std::string &task) {
    tasks.push_back(task);
    save();
  }

  void edit(size_t index, const std::string &task) {
    if (index >= 0 && index < tasks.size()) {
      tasks[index] = task;
    }
    save();
  }

  void remove(size_t index) {
    if (index >= 0 && index < tasks.size()) {
      tasks.erase(tasks.begin() + index);
    }
    save();
  }

  void print() {
    for (size_t i = 0; i < tasks.size(); i++) {
      std::cout << i + 1 << ") " << tasks[i] << std::endl;
    }
  }

  bool isEmpty() { return tasks.empty(); }

 private:
  std::vector<std::string> tasks;
  std::string file_name; 

  void save() {
    std::ofstream outfile(file_name);
    if (outfile.is_open()) {
      for (const std::string &item : tasks) {
        outfile << item << std::endl;
      }
    } else {
      std::cerr << "Error opening file: " << file_name << std::endl;
    }
  }
};

std::string getUserInput() {
  std::string userInput;
  std::getline(std::cin, userInput);
  return userInput;
}

int main() {
  std::string userInput;
  TodoList todoList(SAVE_FILE_NAME);
  std::cout << "TO-DO LIST" << std::endl;
  std::cout << "Developed by Matteo Paoli - v" << SW_VERSION << std::endl;
  std::cout << "\n";

  while (true) {
    if (todoList.isEmpty()) {
      std::cout << "Your to-do list is empty" << std::endl;
    } else {
      std::cout << "Here is your current to-do list" << std::endl;
      todoList.print();
    }
    std::cout << "What do you wanna do? (add / delete / edit)" << std::endl;
    userInput = getUserInput();
    if (userInput == "add") {
      std::cout << "Enter your activity: ";
      todoList.add(getUserInput());
    } else if (userInput == "delete") {
      if (todoList.isEmpty()) {
        std::cout << "You have no items in your list." << std::endl;
      } else {
        todoList.print();
        std::cout << "Which one do you want to delete? ";
        size_t indexToRemove = std::stoul(getUserInput()) - 1;
        todoList.remove(indexToRemove);
      }
    } else if (userInput == "edit") {
      if (todoList.isEmpty()) {
        std::cout << "You have no items in your list." << std::endl;
      } else {
        todoList.print();
        std::cout << "Which one do you want to edit? ";
        size_t indexToEdit = std::stoul(getUserInput()) - 1;
        std::cout << "Edit the item" << std::endl;
        todoList.edit(indexToEdit, getUserInput()); 
      }
    } else {
      std::cout << "Invalid input" << std::endl;
    }
  }
  return 0;
}
