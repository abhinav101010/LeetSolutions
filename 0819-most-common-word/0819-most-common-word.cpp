#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> count;
        
        string word;
        for (char c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (bannedSet.find(word) == bannedSet.end()) {
                    count[word]++;
                }
                word.clear();
            }
        }
        if (!word.empty() && bannedSet.find(word) == bannedSet.end()) {
            count[word]++;
        }
        
        string result;
        int maxCount = 0;
        for (auto& [w, c] : count) {
            if (c > maxCount) {
                maxCount = c;
                result = w;
            }
        }
        return result;
    }
};