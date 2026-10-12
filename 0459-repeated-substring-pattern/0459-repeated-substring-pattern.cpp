class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string search = doubled.substr(1, doubled.size() - 2);
        return search.find(s) != string::npos;
    }
};