#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        std::vector<std::vector<char>> codes;
        while (!file.eof()) {
            getline(file, line);
                codes.push_back(std::vector<char>(line.begin(), line.end()));
        }
        for (size_t i = 0; i < codes.size(); i++) {
            for (size_t j = i; j < codes.size(); j++) {
                auto str1 = codes[i];
                auto str2 = codes[j];
                std::string same_chars = "";
                uint64_t diff_chars = 0;
                for (size_t k = 0; k < str1.size(); k++) {
                    if (str1[k] != str2[k]) {
                        diff_chars++;
                    } else {
                        same_chars.append(1, str1[k]);
                    }
                }
                if (diff_chars == 1) {
                    std::cout << "SOLLUTION: " << same_chars << std::endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}
