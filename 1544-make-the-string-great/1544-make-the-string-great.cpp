class Solution {
public:
    string makeGood(string s) {
        string st;

        for (char ch : s) {
            if (!st.empty() && abs(st.back() - ch) == 32) {
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }

        return st;
    }
};
