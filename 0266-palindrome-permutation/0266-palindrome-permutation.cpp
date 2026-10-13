class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> st;
        for (char c : s) {
            if (st.count(c)) st.erase(c);
            else st.insert(c);
        }
        return st.size() <= 1;
    }
};