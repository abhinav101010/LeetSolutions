#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {0};
        for (char c : chars) cnt[c - 'a']++;
        int ans = 0;
        for (auto& w : words) {
            int wc[26] = {0};
            bool ok = true;
            for (char c : w) {
                wc[c - 'a']++;
                if (wc[c - 'a'] > cnt[c - 'a']) { ok = false; break; }
            }
            if (ok) ans += w.size();
        }
        return ans;
    }
};
