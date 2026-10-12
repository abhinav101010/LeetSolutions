class Solution {
public:
    char findTheDifference(string s, string t) {
        int sCount = 0;
        int tCount = 0;
        for (char c : s) {
            sCount += c;
        }
        for (char c : t) {
            tCount += c;
        }
        return char(tCount - sCount);
    }
};