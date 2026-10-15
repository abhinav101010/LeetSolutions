#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto sGroups = getGroups(s);
        int ans = 0;
        for (const string& w : words) {
            auto wGroups = getGroups(w);
            if (wGroups.size() != sGroups.size()) continue;
            bool ok = true;
            for (size_t i = 0; i < sGroups.size(); i++) {
                auto g1 = wGroups[i];
                auto g2 = sGroups[i];
                if (g1.first != g2.first) { ok = false; break; }
                if (g1.second > g2.second) { ok = false; break; }
                if (g1.second < g2.second && g2.second < 3) { ok = false; break; }
            }
            if (ok) ans++;
        }
        return ans;
    }
private:
    vector<pair<char,int>> getGroups(const string& st) {
        vector<pair<char,int>> groups;
        int i = 0;
        while (i < st.size()) {
            int j = i;
            while (j < st.size() && st[j] == st[i]) {
                j++;
            }
            groups.push_back({st[i], j - i});
            i = j;
        }
        return groups;
    }
};
