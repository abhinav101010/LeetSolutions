class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int chars[26] = {0};
        for (char c : magazine) {
            chars[c - 'a']++;
        }

        for (char c : ransomNote) {
            int idx = c - 'a';
            if (chars[idx] == 0) {
                return false;
            }
            chars[idx]--;
        }
        return true;
    }
};