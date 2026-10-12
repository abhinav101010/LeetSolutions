class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26, 0);
        for (const string& word : words) {
            for (char ch : word) {
                count[ch - 'a']++;
            }
        }
        int n = words.size();
        for (int freq : count) {
            if (freq % n != 0) {
                return false;
            }
        }
        return true;
    }
};