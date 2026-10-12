class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) {
            return "";
        }

        unordered_set<char> chars(s.begin(), s.end());

        for (int i = 0; i < (int)s.size(); i++) {
            char ch = s[i];
            if (!chars.count(tolower(ch)) || !chars.count(toupper(ch))) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                return left.size() >= right.size() ? left : right;
            }
        }

        return s;
    }
};