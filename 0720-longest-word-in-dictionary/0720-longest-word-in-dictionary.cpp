#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        set.insert("");
        vector<string> list(set.begin(), set.end());
        sort(list.begin(), list.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return b.size() < a.size(); // descending length
            }
            return a < b; // ascending lexicographically
        });
        for (string& w : list) {
            bool ok = true;
            for (int i = 1; i <= (int)w.size(); i++) {
                if (set.find(w.substr(0, i)) == set.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
};
