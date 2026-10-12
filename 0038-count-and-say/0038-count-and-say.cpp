class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (n > 1) {
            string next;
            int i = 0;
            while (i < (int)s.size()) {
                int j = i;
                while (j < (int)s.size() && s[j] == s[i]) {
                    j++;
                }
                next += to_string(j - i);
                next += s[i];
                i = j;
            }
            s = next;
            n--;
        }
        return s;
    }
};
