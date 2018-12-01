#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

int64_t find_double_freq(std::vector<int64_t> freq_list);

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        std::vector<int64_t> frequency_list;
        while (!file.eof()) {
            getline(file, line);
            frequency_list.push_back(std::stoi(line));
        }
        std::cout << "SOLLUTION: " << find_double_freq(frequency_list) << std::endl;
        return 0;
    }
    return 1;
}

int64_t find_double_freq(std::vector<int64_t> freq_list) {
    std::unordered_set<int64_t> reached_freqs;
    int64_t freq = 0;
    while (true) {
        for (int64_t number : freq_list) {
            if (reached_freqs.find(freq) == reached_freqs.end()) {
                reached_freqs.insert(freq);
                freq += number;
            }
            else {
                return freq;
            }
        }
    }
}
