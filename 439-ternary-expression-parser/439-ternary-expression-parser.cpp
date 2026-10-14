#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;
        int i = expression.size() - 1;
        while (i >= 0) {
            char ch = expression[i];
            if (!st.empty() && st.top() == '?') {
                st.pop(); // '?'
                char trueVal = st.top(); st.pop();
                char falseVal = st.top(); st.pop();
                char condition = st.top(); st.pop(); // 'T' or 'F'
                if (condition == 'T') {
                    st.push(trueVal);
                } else {
                    st.push(falseVal);
                }
                i--; // skip condition
            } else {
                st.push(ch);
            }
            i--;
        }
        return string(1, st.top());
    }
};
