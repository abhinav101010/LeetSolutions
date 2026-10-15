#include <string>
#include <stack>
#include <unordered_map>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        unordered_map<char, int> precedence = {{'+',1},{'-',1},{'*',2},{'/',2}};
        int n = s.size();
        int i = 0;
        while (i < n) {
            char ch = s[i];
            if (ch == ' ') {
                i++;
                continue;
            }
            if (isdigit(ch)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                operands.push(num);
                continue;
            }
            if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    applyOp(operands, operators);
                }
                operators.pop(); // remove '('
            } else {
                while (!operators.empty() && operators.top() != '(' && 
                       precedence[operators.top()] >= precedence[ch]) {
                    applyOp(operands, operators);
                }
                operators.push(ch);
            }
            i++;
        }
        while (!operators.empty()) {
            applyOp(operands, operators);
        }
        return operands.empty() ? 0 : operands.top();
    }
    
    void applyOp(stack<int>& operands, stack<char>& operators) {
        int b = operands.top(); operands.pop();
        int a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        switch (op) {
            case '+': operands.push(a + b); break;
            case '-': operands.push(a - b); break;
            case '*': operands.push(a * b); break;
            case '/': 
                if (a * b < 0) {
                    operands.push(-(abs(a) / abs(b)));
                } else {
                    operands.push(a / b);
                }
                break;
        }
    }
};
