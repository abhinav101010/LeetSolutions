class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            size_t lo = word.find(c);
            size_t up = word.find(toupper(c));
            if (lo != string::npos && up != string::npos) {
                if (word.rfind(c) < up) {
                    ans++;
                }
            }
        }
        return ans;
    }
};