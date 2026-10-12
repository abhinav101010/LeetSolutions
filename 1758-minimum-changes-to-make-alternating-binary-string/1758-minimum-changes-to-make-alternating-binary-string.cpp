class Solution {
public:
    int minOperations(string s) {
        int changes1 = 0;
        int changes2 = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '0' + (i % 2)) {
                changes1++;
            }
            if (s[i] != '0' + (1 - (i % 2))) {
                changes2++;
            }
        }

        return min(changes1, changes2);
    }
};