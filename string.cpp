#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string sentence = "C++ is fast and powerful";
    std::stringstream ss(sentence);
    std::string word;
    std::vector<std::string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    for (const auto& w : words) {
        std::cout << w << "\n";
    }

    return 0;
}
