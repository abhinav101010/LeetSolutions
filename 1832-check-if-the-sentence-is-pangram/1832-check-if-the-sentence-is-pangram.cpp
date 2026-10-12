class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);
        for (char ch : sentence) {
            seen[ch - 'a'] = true;
        }
        for (bool b : seen) {
            if (!b) return false;
        }
        return true;
    }
};