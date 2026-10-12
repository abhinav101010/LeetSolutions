class Solution {
private:
    unordered_map<string, vector<int>> memo;
    
public:
    vector<int> diffWaysToCompute(string expression) {
        memo.clear();
        return compute(expression);
    }
    
private:
    vector<int> compute(const string& expr) {
        if (memo.count(expr)) return memo[expr];
        
        vector<int> result;
        bool isNumber = true;
        
        for (int i = 0; i < (int)expr.size(); i++) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*') {
                isNumber = false;
                vector<int> left = compute(expr.substr(0, i));
                vector<int> right = compute(expr.substr(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') result.push_back(l + r);
                        else if (c == '-') result.push_back(l - r);
                        else if (c == '*') result.push_back(l * r);
                    }
                }
            }
        }
        
        if (isNumber) {
            result.push_back(stoi(expr));
        }
        
        memo[expr] = result;
        return result;
    }
};