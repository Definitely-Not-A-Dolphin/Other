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

std::string getElement(std::string fileName, int row, int column);
std::string getElementChar(std::string fileName, int row, int column);

int main() {

  std::cout << getElementChar("Words1.csv", 2, 2) << std::endl;

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
  getline(file, output, ',');

  std::string tmp; // A string to store the word on each iteration.
  std::stringstream str_strm(output);
  std::vector<std::string> wordsVector; // Create vector to hold our words
  while (str_strm >> tmp) {
    tmp.pop_back();
    wordsVector.push_back(tmp);
  };

  file.close();

  return wordsVector.at(column - 1);
}

std::string getElementChar(std::string fileName, int row, int column) {
  std::ifstream file(fileName, std::ios::in);

  pointerMover(file, row);

  int counter = 0;

  while (true) {

    std::cout << "loop!" << std::endl;

    char destination[36];

    file.get(destination, 36, ',');

    std::string output = destination;

    counter++;

    std::cout << counter << std::endl << column << std::endl;

    if (counter == column) {
      std::cout << output << std::endl;

      file.close();
      return output;
    }
  };
}