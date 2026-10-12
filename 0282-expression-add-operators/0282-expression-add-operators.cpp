class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }
    
private:
    void backtrack(const string& num, int target, int index, string path, long eval, long prev, vector<string>& result) {
        if (index == (int)num.size()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = index; i < (int)num.size(); i++) {
            if (i > index && num[index] == '0') break;
            string currStr = num.substr(index, i - index + 1);
            long curr = stol(currStr);
            
            if (index == 0) {
                backtrack(num, target, i + 1, currStr, curr, curr, result);
            } else {
                backtrack(num, target, i + 1, path + "+" + currStr, eval + curr, curr, result);
                backtrack(num, target, i + 1, path + "-" + currStr, eval - curr, -curr, result);
                backtrack(num, target, i + 1, path + "*" + currStr, eval - prev + prev * curr, prev * curr, result);
            }
        }
    }
};