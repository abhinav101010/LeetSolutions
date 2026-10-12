class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool ok[26] = {false};
        for (char c : allowed) ok[c - 'a'] = true;

        int count = 0;
        for (const string& w : words) {
            bool consistent = true;
            for (char c : w) {
                if (!ok[c - 'a']) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
};