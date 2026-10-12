class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size()) return result;
        
        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;
        for (int i = 0; i < (int)p.size(); i++) sCount[s[i] - 'a']++;
        
        if (pCount == sCount) result.push_back(0);
        
        for (int i = p.size(); i < (int)s.size(); i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - p.size()] - 'a']--;
            if (pCount == sCount) result.push_back(i - p.size() + 1);
        }
        
        return result;
    }
};