class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> level = {s};
        
        while (true) {
            vector<string> valid;
            for (const string& str : level) {
                if (isValid(str)) valid.push_back(str);
            }
            if (!valid.empty()) return valid;
            
            unordered_set<string> nextLevel;
            for (const string& str : level) {
                for (int i = 0; i < (int)str.size(); i++) {
                    if (str[i] == '(' || str[i] == ')') {
                        nextLevel.insert(str.substr(0, i) + str.substr(i + 1));
                    }
                }
            }
            level = move(nextLevel);
        }
    }
    
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};