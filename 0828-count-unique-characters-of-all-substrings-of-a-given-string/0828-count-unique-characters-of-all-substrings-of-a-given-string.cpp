#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> pos(26);
        // count occurrences
        vector<int> cnt(26,0);
        for (char c : s) {
            cnt[c-'A']++;
        }
        for (int i = 0; i < 26; i++) {
            pos[i].resize(cnt[i] + 2, -1); // will fill later
            pos[i][0] = -1;
            pos[i][cnt[i]+1] = (int)s.size();
        }
        vector<int> idx(26,0);
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'A';
            pos[c][idx[c]+1] = i;
            idx[c]++;
        }
        long ans = 0;
        for (int c = 0; c < 26; c++) {
            for (int i = 1; i <= idx[c]; i++) {
                ans += (long)(pos[c][i] - pos[c][i-1]) * (pos[c][i+1] - pos[c][i]);
            }
        }
        return (int) ans;
    }
};
