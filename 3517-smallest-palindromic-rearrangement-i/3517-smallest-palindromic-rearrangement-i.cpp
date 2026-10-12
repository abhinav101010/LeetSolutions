class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string half;
        char middle = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int idx = c - 'a';
            half.append(count[idx] / 2, c);
            if (count[idx] % 2 == 1) {
                middle = c;
            }
        }
        string rev = half;
        reverse(rev.begin(), rev.end());
        return half + (middle == 0 ? "" : string(1, middle)) + rev;
    }
};