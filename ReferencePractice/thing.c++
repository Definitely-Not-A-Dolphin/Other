#include <iostream>
#include <vector>
#include <string>

int main() {

  std::string sana1 = "Sana1", sana2 = "Sana2", sana3 = "Sana3";

  std::string &word1 = sana1, &word2 = sana2, &word3 = sana3;

  std::cout << sana1 << std::endl << word1 << std::endl; 

  return 0;
}