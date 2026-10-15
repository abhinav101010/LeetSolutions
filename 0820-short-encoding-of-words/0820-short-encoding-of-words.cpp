#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        for (string& word : words) {
            for (int i = 1; i < word.length(); i++) {
                set.erase(word.substr(i));
            }
        }
        int res = 0;
        for (const string& w : set) {
            res += w.size() + 1;
        }
        return res;
    }
};
