#include <iostream>
#include <fstream>
#include <string>
#include <list>

uint64_t get_number_of_remaining_polymers(std::string);

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        getline(file, line);
        std::cout << "SOLUTION: " << get_number_of_remaining_polymers(line) << std::endl;
    }
    return 1;
}

uint64_t get_number_of_remaining_polymers(std::string polymer) {
    std::list<char> polymer_chain(polymer.begin(), polymer.end());
    bool change = true;
    while (change) {
        change = false;
        auto it = polymer_chain.begin();
        while (it != polymer_chain.end()) {
            while (*it + 32 == *std::next(it) || *it == *std::next(it) + 32) {
                change = true;
                it = polymer_chain.erase(it);
                it = polymer_chain.erase(it);
            }
            it = std::next(it);
        }
    }
    return std::string(polymer_chain.begin(), polymer_chain.end()).size();
}
