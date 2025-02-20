#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

void moveToLine(std::fstream &file, int k) {

  file.seekg(std::ios::beg);

  std::string line;
  for (int currentLine = 1; currentLine < k; currentLine++) {
    getline(file, line);
  };
}
void moveToCell(std::fstream &file, int row, int column);

int fileSize(std::string fileName);

int randomInt(int lower, int upper) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(lower, upper);

  int randomX = dis(gen);

  return randomX;
}

bool vectorChecker(std::vector<std::string> searchedVector,
                   std::string searchedWord) {
  bool result = false;

  for (std::string comparer : searchedVector) {
    if (comparer == searchedWord) {
      result = true;
    }
  };

  return result;
}
bool vectorCheckerInt(std::vector<int> searchedVector, int searchedInt) {

  bool result = false;

  for (int h = 0; h <= searchedVector.size(); h++) {
    if (h == searchedInt) {
      result = true;
      break;
    };
  };

  return result;
}

std::string trimWhiteSpace(std::string input);
std::string readCell(std::fstream &file, int row, int column);

void logIn(std::fstream &file);
void createAccount(std::fstream &file);

int main() {

  std::fstream readUserFile("userFile.csv");

  std::cout << "Log in or create account? " << std::endl
            << "  Log in: type 1: " << std::endl
            << "  Create account: type 2: " << std::endl;
  std::string answer1;
  std::getline(std::cin, answer1);
  
  if (answer1 == "1") {
    logIn(readUserFile);
  } else if (answer1 == "2") {
    createAccount(readUserFile);
  };

  readUserFile.close();

  return 0;
}

void logIn(std::fstream &file) {

  std::cout << "Give your name: ";
  std::string name;
  std::getline(std::cin, name);
  std::cout << std::endl;

  std::cout << "Give your username: ";
  std::string username;
  std::getline(std::cin, username);
  std::cout << std::endl;

  bool found = false;

  for (int l = 1; l <= fileSize("userFile.csv"); l++) {

    if (readCell(file, l, 1) == name) {

      if (readCell(file, l, 2) == username) {
        std::cout << "Match found!" << std::endl;
      } else {
        std::cout << "Wrong username" << std::endl;
      };

      found = true;
      break;
    };
  };

  if (!found) {
    std::cout << "Match not found!" << std::endl;
  };
}
void createAccount(std::fstream &file) {
  std::cout << "Give your name: ";
  std::string name;
  std::getline(std::cin, name);
  std::cout << std::endl;

  std::cout << "Give your username: ";
  std::string username;
  std::getline(std::cin, username);
  std::cout << std::endl;

  file.seekg(0,std::ios::end);

  file << "\n" << name << ", " << username << ",";
}

int fileSize(std::string fileName) {
  std::fstream file(fileName);

  int lineCounter = 0;
  std::string output;

  while (getline(file, output)) {
    lineCounter++;
  };

  file.close();

  return lineCounter;
}

void moveToCell(std::fstream &file, int row, int column) {
  moveToLine(file, row);

  std::string output;

  for (int k = 1; k < column; k++) {
    getline(file, output, ',');
  };
}

std::string readCell(std::fstream &file, int row, int column) {

  moveToCell(file, row, column);

  std::string output;
  std::getline(file, output, ',');
  output = trimWhiteSpace(output);
  return output;
}

std::string trimWhiteSpace(std::string input) {
  if (input[0] == ' ') {
    input.erase(input.begin());
  };

  while (input[input.size() - 1] == ' ') {
    input.pop_back();
  };

  return input;
}