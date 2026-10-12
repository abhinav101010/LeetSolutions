class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenZero = false;

        for (char ch : s) {
            if (ch == '0') {
                seenZero = true;
            } else if (seenZero) {
                return false;
            }
        }

        return true;
    }
};