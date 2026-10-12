#include <string>
#include <cctype>

class Solution {
public:
    bool detectCapitalUse(std::string word) {
        bool allUpper = true, allLower = true, firstUpperRestLower = true;
        for (size_t i = 0; i < word.size(); ++i) {
            if (std::islower(word[i])) allUpper = false;
            if (std::isupper(word[i])) allLower = false;
            if (i == 0 && std::islower(word[i])) firstUpperRestLower = false;
            if (i > 0 && std::isupper(word[i])) firstUpperRestLower = false;
        }
        return allUpper || allLower || firstUpperRestLower;
    }
};