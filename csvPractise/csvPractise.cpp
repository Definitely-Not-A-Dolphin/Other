#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

std::ifstream readFile("Words.csv");

std::string getElement(int row, int column);

void pointerMover(std::ifstream &file, int k);

int main() {

  std::cout << getElement(2, 4) << std::endl;

  return 0;
}

std::string getElement(int row, int column) {
  pointerMover(readFile, row);

  std::string output;
  std::getline(readFile, output);

  std::string tmp; // A string to store the word on each iteration.
  std::stringstream str_strm(output);
  std::vector<std::string> wordsVector; // Create vector to hold our words
  while (str_strm >> tmp) {
    tmp.pop_back();
    wordsVector.push_back(tmp);
  }

  return wordsVector.at(column - 1);
}

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