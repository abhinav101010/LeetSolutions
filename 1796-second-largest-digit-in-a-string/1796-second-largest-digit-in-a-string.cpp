class Solution {
public:
    int secondHighest(string s) {
        unordered_set<int> digits;

        for (char ch : s) {
            if (isdigit(ch)) {
                digits.insert(ch - '0');
            }
        }

        if (digits.size() < 2) {
            return -1;
        }

        int max = *max_element(digits.begin(), digits.end());
        digits.erase(max);
        return *max_element(digits.begin(), digits.end());
    }
};