#include <string>
#include <numeric>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int length = std::gcd(static_cast<int>(str1.length()), static_cast<int>(str2.length()));
        return str1.substr(0, length);
    }
};