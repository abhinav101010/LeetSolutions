class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        vector<int> stack;
        
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == (int)s.size() - 1) {
                if (sign == '+') stack.push_back(num);
                else if (sign == '-') stack.push_back(-num);
                else if (sign == '*') {
                    int prev = stack.back(); stack.pop_back();
                    stack.push_back(prev * num);
                }
                else if (sign == '/') {
                    int prev = stack.back(); stack.pop_back();
                    stack.push_back(prev / num);
                }
                sign = c;
                num = 0;
            }
        }
        
        int result = 0;
        for (int x : stack) result += x;
        return result;
    }
};