#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> fileNameVector = {"fileOne.csv", "fileTwo.csv",
                                           "fileThree.csv"};

void pointerMover(std::ifstream &file, int k) {

  // Special thanks to Elses/Menium for writing this part!

  file.clear();
  file.seekg(0, std::ios::beg);

  std::string line;
  for (int currentLine = 1; currentLine < k; currentLine++) {
    if (!std::getline(file, line)) {
      std::cerr << "Error: Line " << k << " does not exist!" << std::endl;
      return;
    }
  }
}

int fileSize(std::ifstream &file);

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

std::string getElement(std::ifstream &file, int row, int column);
std::string getElementChar(std::string fileName, int row, int column);

int main() {

  std::string thorn = " thorn ";

  std::cout << thorn.size() << std::endl;

  std::cout << trimWhiteSpace(" thorn ") << std::endl << trimWhiteSpace(thorn);

  return 0;
}

int fileSize(std::ifstream &file) {
  int lineCounter = 0;
  std::string output;

  while (getline(file, output)) {
    lineCounter++;
  };

  return lineCounter;
}

std::string getElement(std::ifstream &file, int row, int column) {

  pointerMover(file, row);

  std::string output;

  std::vector<std::string> wordsVector = {};

  while (getline(file, output, ',')) {
    output = trimWhiteSpace(output);

    wordsVector.push_back(output);

    output.erase();
  };

  return wordsVector.at(column - 1);
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