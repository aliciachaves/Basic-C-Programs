#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {

    std::string str;
    std::map<std::string, int> words;

    while (std::getline(std::cin, str)) {
        std::istringstream iss(str);
        std::string word;
        while (iss >> word) {
            if (!word.empty()) {
                auto it = words.find(word);
                if (it != words.end()) {
                    it->second++;
                }
                else {
                    words.insert({word, 1});
                }
            }
        }
    }
    
    int max_val = 1;
    std::string max_word = "";
    for (const auto& [word, val] : words) {
        if (val >= max_val) {
            max_word = word;
            max_val = val;
        }
    }
    std::cout << max_word << std::endl;

    return 0;
}
