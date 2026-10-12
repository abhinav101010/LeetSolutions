class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> numbers;
        string current;

        for (char ch : word) {
            if (isdigit(ch)) {
                current += ch;
            } else {
                if (!current.empty()) {
                    numbers.insert(removeLeadingZeros(current));
                    current.clear();
                }
            }
        }

        if (!current.empty()) {
            numbers.insert(removeLeadingZeros(current));
        }

        return numbers.size();
    }

private:
    string removeLeadingZeros(const string& s) {
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }
        return i == s.size() ? "0" : s.substr(i);
    }
};