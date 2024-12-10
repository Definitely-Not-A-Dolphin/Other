#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <list>
#include <string>
#include <sstream>

std::ifstream readFile("Words.csv");


int main() {

    std::string output;
    std::getline(readFile, output);

    std::cout << output;

    return 0;
}