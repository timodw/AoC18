#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

uint64_t get_number_of_remaining_polymers(std::string);

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        getline(file, line);
        uint64_t min_nr_polymers = line.size();
        for (char c = 65; c < 91; c++) {
            std::cout << c << std::endl;
            std::string line_copy(line);
            line_copy.erase(std::remove(line_copy.begin(), line_copy.end(), c), line_copy.end());
            line_copy.erase(std::remove(line_copy.begin(), line_copy.end(), c + 32), line_copy.end());
            std::cout << c << std::endl;
            uint64_t nr_polymers = get_number_of_remaining_polymers(line_copy);
            if (nr_polymers < min_nr_polymers) {
                min_nr_polymers = nr_polymers;
            }
        }
        std::cout << "SOLUTION: " << min_nr_polymers << std::endl;
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
            while (it != std::prev(polymer_chain.end()) && (*it + 32 == *std::next(it) || *it == *std::next(it) + 32)) {
                change = true;
                it = polymer_chain.erase(it);
                it = polymer_chain.erase(it);
            }
            it = std::next(it);
        }
    }
    return std::string(polymer_chain.begin(), polymer_chain.end()).size();
}
