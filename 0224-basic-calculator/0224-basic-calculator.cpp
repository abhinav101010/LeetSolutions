class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int sign = 1;
        int result = 0;
        vector<int> stack;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stack.push_back(result);
                stack.push_back(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= stack.back(); stack.pop_back();  // sign
                result += stack.back(); stack.pop_back();  // previous result
            }
        }
        
        return result + sign * num;
    }
};