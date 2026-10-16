#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }
        for (int i = 0; i < (int)words.size()-1; i++) {
            if (!isLessOrEqual(words[i], words[i+1], rank)) {
                return false;
            }
        }
        return true;
    }
private:
    bool isLessOrEqual(const string& s1, const string& s2, const vector<int>& rank) {
        int n = min(s1.size(), s2.size());
        for (int i = 0; i < n; i++) {
            int c1 = rank[s1[i] - 'a'];
            int c2 = rank[s2[i] - 'a'];
            if (c1 < c2) return true;
            if (c1 > c2) return false;
        }
        return s1.size() <= s2.size();
    }
};
