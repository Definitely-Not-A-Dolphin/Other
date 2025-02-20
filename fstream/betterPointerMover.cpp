#include <fstream>
#include <iostream>
#include <string>

void pointerMover2(std::fstream &file, int line, std::string pos);

int main() {

  std::fstream file("userFile.csv");

  file.seekg(std::fstream::beg);

  std::cout << file.tellg() << " " << file.tellp() << std::endl;

  std::string dest;
  std::getline(file, dest, ',');
  std::cout << dest << std::endl;

  std::cout << file.tellg() << " " << file.tellp() << std::endl;

  file.seekg(std::fstream::end);

  std::cout << file.tellg() << " " << file.tellp() << std::endl;

  return 0;
}

void seekLine(std::fstream &file, int line, std::string pos) {}