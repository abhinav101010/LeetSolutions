class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (k > 0 && !stack.empty() && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        
        while (k > 0) {
            stack.pop_back();
            k--;
        }
        
        int pos = stack.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return stack.substr(pos);
    }
};