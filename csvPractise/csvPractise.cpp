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

  for (int g = 1; g <= 4; g++) {
    for (int h = 1; h <= 4; h++) {
      std::cout << getElement("Words1.csv", h, g) << std::endl;
    };
  };

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

    wordsVector.push_back(output);

    output.erase();
  };

  file.close();

  return wordsVector.at(column - 1);
}

std::string getElementChar(std::string fileName, int row, int column) {

  std::ifstream readFile(fileName, std::ios::in);

  pointerMover(readFile, row);

  struct {
    char thing1[36];
    char thing2[36];
    char thing3[36];
    char thing4[36];
    char thing5[36];
    char thing6[36];
  } val;

  struct {
    std::string thing1;
    std::string thing2;
    std::string thing3;
    std::string thing4;
    std::string thing5;
    std::string thing6;
  } tpt;

  std::vector<char *> charVector = {val.thing1, val.thing2, val.thing3,
                                    val.thing4, val.thing5, val.thing6};

  std::vector<std::string> strVector = {tpt.thing1, tpt.thing2, tpt.thing3,
                                        tpt.thing4, tpt.thing5, tpt.thing6};

  int g;

  for (int gloop = 1; gloop <= column; gloop++) {

    readFile.get(charVector.at(gloop), 36, ',');
    readFile.seekg(1, std::ifstream::cur);

    strVector.at(gloop) = charVector.at(gloop);

    if (gloop == column) {
      readFile.close();
      g = gloop;
    };
  };

  strVector.at(g).erase(strVector.at(g).begin());

  return strVector.at(g);
}