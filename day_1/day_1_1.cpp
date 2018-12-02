#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        uint64_t two_times = 0;
        uint64_t three_times = 0;
        while (!file.eof()) {
            getline(file, line);
            std::unordered_map<char, uint64_t> counts;
            for (char c : line) {
                counts[c]++;
            }
            uint64_t two_present = 0;
            uint64_t three_present = 0;
            for (auto kv : counts) {
                if (kv.second == 2) {
                    two_present |= 1;
                } else if (kv.second == 3) {
                    three_present |= 1;
                }
            }
            two_times += two_present;
            three_times += three_present;
        }
        std::cout << "SOLLUTION: " << two_times * three_times << std::endl;
        return 0;
    }
    return 1;
}
