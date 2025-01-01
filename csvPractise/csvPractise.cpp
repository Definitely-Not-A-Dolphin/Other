#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

std::string fileName;

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

std::string getElement(std::string fileName, int row, int column);
std::string getElementChar(std::string fileName, int row, int column);

int main() {

  std::cout << getElement("Words1.csv", 6, 1);

  return 0;
}

int fileSize(std::string fileName) {
  std::ifstream file(fileName, std::ios::in);

  int lineCounter = 0;
  std::string output;

  while (getline(file, output)) {
    lineCounter += 1;
  }
  file.close();

  return lineCounter;
}

std::string getElement(std::string fileName, int row, int column) {

  std::ifstream file(fileName, std::ios::in);

  pointerMover(file, row);

  std::string output;

  std::vector<std::string> wordsVector = {};

  while (getline(file, output, ',')) {
    if (output[0] == ' ') {
      output.erase(output.begin());
    };

    while (output[output.size() - 1] == ' ') {
      output.pop_back();
    };

    wordsVector.push_back(output);

    output.erase();
  };

  file.close();

  return wordsVector.at(column - 1);
}