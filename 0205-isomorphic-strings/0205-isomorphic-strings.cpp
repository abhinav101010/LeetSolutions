class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> mapStoT(256, -1);
        vector<int> mapTtoS(256, -1);
        for (int i = 0; i < s.length(); ++i) {
            char sc = s[i];
            char tc = t[i];
            if (mapStoT[sc] == -1 && mapTtoS[tc] == -1) {
                mapStoT[sc] = tc;
                mapTtoS[tc] = sc;
            } else if (mapStoT[sc] != tc || mapTtoS[tc] != sc) {
                return false;
            }
        }
        return true;
    }
};