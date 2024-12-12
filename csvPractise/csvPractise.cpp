#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

std::string getElement(std::string fileName, int row, int column);

int fileSize(std::string fileName);

void pointerMover(std::string fileName, int k);

int main() {

  std::cout << getElement("Words2.csv", 4, 3) << std::endl;

  std::cout << fileSize("Words1.csv") << std::endl;

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
  std::ifstream file(fileName);
  pointerMover(fileName, row);

  std::string output;
  std::getline(file, output);

  std::string tmp; // A string to store the word on each iteration.
  std::stringstream str_strm(output);
  std::vector<std::string> wordsVector; // Create vector to hold our words
  while (str_strm >> tmp) {
    tmp.pop_back();
    wordsVector.push_back(tmp);
  }

  file.close();

  return wordsVector.at(column - 1);
}

void pointerMover(std::string fileName, int k) {
  // Special thanks to Elses/Menium for writing this part!
  std::ifstream file(fileName, std::ios::in);

  file.clear();
  file.seekg(0, std::ios::beg);

  std::string line;
  for (int currentLine = 1; currentLine < k; currentLine++) {
    if (!std::getline(file, line)) {
      std::cerr << "Error: Line " << k << " does not exist!" << std::endl;
      return;
    }
  }
  file.close();
}