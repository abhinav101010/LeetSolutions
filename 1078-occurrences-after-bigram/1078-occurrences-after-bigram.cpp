#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    std::vector<std::string> findOcurrences(std::string text, std::string first, std::string second) {
        std::vector<std::string> words;
        std::stringstream ss(text);
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        std::vector<std::string> ans;
        for (int i = 0; i + 2 < (int)words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                ans.push_back(words[i + 2]);
            }
        }

        return ans;
    }
};