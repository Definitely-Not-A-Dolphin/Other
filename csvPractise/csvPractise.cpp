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

int fileSize(std::ifstream &file);

int main() {

  std::cin >> fileName;

  std::ifstream readFile(fileName, std::ios::in);

  std::cout << std::endl << fileSize(readFile);  

  return 0;
}

<<<<<<< Updated upstream
int fileSize(std::ifstream &file) {
  int lineCount = 0;
=======
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

std::string getElement(std::ifstream &file, int row, int column) {
  pointerMover(file, row);
>>>>>>> Stashed changes

  std::string output;
  while (getline(file, output, '\n')) {
    lineCount += 1;
  }
  return lineCount;
}