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
    bool does_overlap;

    Claim(uint64_t id, uint64_t x, uint64_t y, uint64_t x_size, uint64_t y_size) :
        id(id), x(x), y(y), x_size(x_size), y_size(y_size) {does_overlap = false;}
    bool overlaps(Claim&);
};

Claim process_line(std::string);
uint64_t process_overlaps(std::vector<Claim>&);

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        std::vector<Claim> claims;
        while (!file.eof()) {
            getline(file, line);
            claims.push_back(process_line(line));
        }
        std::cout << "Solution: " << process_overlaps(claims) << std::endl;
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

uint64_t process_overlaps(std::vector<Claim>& claims) {
    for (size_t i = 0; i < claims.size() - 1; i++) {
        for (size_t j = i + 1; j < claims.size(); j++) {
            if (claims[i].overlaps(claims[j])) {
                claims[i].does_overlap = true;
                claims[j].does_overlap = true;
            }
        }
    }
    for (auto claim : claims) {
        if (!claim.does_overlap) return claim.id;
    }
    return -1;
}

bool Claim::overlaps(Claim& other) {
    return this->x < other.x + other.x_size &&
           this->x + this->x_size > other.x &&
           this->y < other.y + other.y_size &&
           this->y + this->y_size > other.y;
}
