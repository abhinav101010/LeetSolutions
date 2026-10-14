#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> lpCount(26, 0);
        for (char c : licensePlate) {
            if (isalpha(c)) {
                lpCount[tolower(c) - 'a']++;
            }
        }
        
        string best = "";
        int bestLen = INT_MAX;
        for (string& w : words) {
            vector<int> wc(26, 0);
            for (char c : w) {
                wc[tolower(c) - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (wc[i] < lpCount[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if ((int)w.size() < bestLen) {
                    bestLen = w.size();
                    best = w;
                }
            }
        }
        return best;
    }
};
