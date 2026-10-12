class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> path;
        return backtrack(num, 0, path);
    }
    
private:
    bool backtrack(const string& num, int index, vector<long long>& path) {
        if (index == (int)num.size()) {
            return path.size() >= 3;
        }
        
        for (int i = index; i < (int)num.size(); i++) {
            if (i > index && num[index] == '0') break;
            string currStr = num.substr(index, i - index + 1);
            long long curr = stoll(currStr);
            
            if (path.size() < 2 || curr == path[path.size() - 1] + path[path.size() - 2]) {
                path.push_back(curr);
                if (backtrack(num, i + 1, path)) return true;
                path.pop_back();
            }
        }
        
        return false;
    }
};