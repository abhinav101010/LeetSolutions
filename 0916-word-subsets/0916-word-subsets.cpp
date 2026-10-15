#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> need(26, 0);
        for (string& b : B) {
            vector<int> cnt(26, 0);
            for (char ch : b) {
                cnt[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                need[i] = max(need[i], cnt[i]);
            }
        }
        vector<string> res;
        for (string& a : A) {
            vector<int> cnt(26, 0);
            for (char ch : a) {
                cnt[ch - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < need[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.push_back(a);
            }
        }
        return res;
    }
};
