#include <string>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string result;
        result.reserve(address.length() + 6);

        for (char ch : address) {
            if (ch == '.') {
                result += "[.]";
            } else {
                result += ch;
            }
        }

        return result;
    }
};