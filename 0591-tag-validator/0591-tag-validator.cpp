#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        if (n == 0 || code[0] != '<') {
            return false;
        }
        vector<string> stack;
        bool seenTag = false;
        int i = 0;
        while (i < n) {
            if (code[i] == '<') {
                if (i + 1 >= n) {
                    return false;
                }
                if (code[i+1] == '!') {
                    // CDATA
                    if (i + 9 > n || code.substr(i, 9) != "<![CDATA[") {
                        return false;
                    }
                    int j = code.find("]]>", i + 9);
                    if (j == -1) {
                        return false;
                    }
                    i = j + 3;
                } else if (code[i+1] == '/') {
                    // end tag
                    int j = code.find('>', i + 2);
                    if (j == -1) {
                        return false;
                    }
                    string tag = code.substr(i+2, j - (i+2));
                    if (!isValidTagName(tag)) {
                        return false;
                    }
                    if (stack.empty() || stack.back() != tag) {
                        return false;
                    }
                    seenTag = true;
                    if (stack.empty() && j + 1 != n) {
                        return false;
                    }
                    i = j + 1;
                    stack.pop_back();
                } else {
                    // start tag
                    int j = code.find('>', i + 1);
                    if (j == -1) {
                        return false;
                    }
                    string tag = code.substr(i+1, j - (i+1));
                    if (!isValidTagName(tag)) {
                        return false;
                    }
                    stack.push_back(tag);
                    i = j + 1;
                }
            } else {
                i++;
            }
        }
        return stack.empty() && seenTag;
    }
    
private:
    bool isValidTagName(const string& tag) {
        if (tag.empty() || tag.size() > 9) {
            return false;
        }
        for (char c : tag) {
            if (!isupper(static_cast<unsigned char>(c))) {
                return false;
            }
        }
        return true;
    }
};
