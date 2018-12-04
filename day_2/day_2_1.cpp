#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stdlib.h>

class Claim {
public:
    uint64_t id;
    uint64_t x;
    uint64_t y;
    uint64_t x_size;
    uint64_t y_size;

    Claim(uint64_t id, uint64_t x, uint64_t y, uint64_t x_size, uint64_t y_size) :
        id(id), x(x), y(y), x_size(x_size), y_size(y_size) {}
};

Claim process_line(std::string);
uint64_t count_overlaps(std::vector<Claim>&);

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        uint64_t fabric[1000*1000] = {};
        uint64_t overlaps = 0;
        while (!file.eof()) {
            getline(file, line);
            Claim claim = process_line(line);
            for (size_t i = claim.x; i < claim.x + claim.x_size; i++) {
                for (size_t j = claim.y; j < claim.y + claim.y_size; j++) {
                    fabric[i*1000 + j] += 1;
                    if (fabric[i*1000 + j] == 2) {
                        overlaps++;
                    }
                }
            }
        }
        std::cout << "Solution: " << overlaps << std::endl;
    }
    return 1;
}



Claim process_line(std::string line) {
    size_t start = 0;
    size_t end = line.find("@");
    uint64_t id = std::stoi(line.substr(1, end - 1));
    start = end + 2;
    end = line.find(",", start);
    uint64_t x = std::stoi(line.substr(start, end - start));
    start = ++end;
    end = line.find(":", start);
    uint64_t y = std::stoi(line.substr(start, end - start));
    start = end + 2;
    end = line.find("x", start);
    uint64_t x_size = std::stoi(line.substr(start, end - start));
    uint64_t y_size = std::stoi(line.substr(++end));
    Claim claim = Claim(id, x, y, x_size, y_size);
    return claim;
}
