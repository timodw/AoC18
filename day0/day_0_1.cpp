#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream file("input.txt");
  if (file.is_open()) {
    std::string line;
    int64_t freq = 0;
    while (!file.eof()) {
      getline(file, line);
      freq += std::stoi(line);
    }
    std::cout << "SOLLUTION: " << freq << std::endl;
    return 0;
  }
  return 1;
}
