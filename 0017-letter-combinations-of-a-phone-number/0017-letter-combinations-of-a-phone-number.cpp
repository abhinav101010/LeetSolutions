class Solution {
public:
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    vector<string> result = {""};
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    for (char d : digits) {
        vector<string> newResult;
        for (string prefix : result) {
            for (char c : mapping[d - '0']) {
                newResult.push_back(prefix + c);
            }
        }
        result = move(newResult);
    }
    return result;
}
};