#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> stack(s.size() + 1, 0);
        int ptr = 0;
        stack[ptr] = 0;
        for (char ch : s) {
            if (ch == '(') {
                ptr++;
                stack[ptr] = 0;
            } else {
                int v = stack[ptr];
                ptr--;
                stack[ptr] += max(2 * v, 1);
            }
        }
        return stack[0];
    }
};
