class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> ans;
        for (char c : word) {
            if (islower(c) && word.find(toupper(c)) != string::npos) {
                ans.insert(c);
            }
        }
        return ans.size();
    }
};