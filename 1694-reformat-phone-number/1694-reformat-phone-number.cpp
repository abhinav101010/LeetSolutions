class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char c : number) {
            if (c != ' ' && c != '-') digits += c;
        }

        string ans;
        int n = digits.size();
        int i = 0;

        while (n - i > 4) {
            ans += digits.substr(i, 3) + "-";
            i += 3;
        }

        int remaining = n - i;
        if (remaining == 4) {
            ans += digits.substr(i, 2) + "-";
            ans += digits.substr(i + 2, 2);
        } else {
            ans += digits.substr(i);
        }

        return ans;
    }
};