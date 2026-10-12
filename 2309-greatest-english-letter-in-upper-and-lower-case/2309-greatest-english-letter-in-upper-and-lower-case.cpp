class Solution {
public:
    string greatestLetter(string s) {
        bool lower[26] = {false};
        bool upper[26] = {false};
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else {
                upper[c - 'A'] = true;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (lower[i] && upper[i]) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};