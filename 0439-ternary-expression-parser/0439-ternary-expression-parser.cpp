#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;
        int n = expression.size();
        for (int i = n - 1; i >= 0; --i) {
            if (expression[i] == '?') {
                char trueChar = st.top();
                st.pop();
                st.pop(); // ':'
                char falseChar = st.top();
                st.pop();
                if (expression[i - 1] == 'T') {
                    st.push(trueChar);
                } else {
                    st.push(falseChar);
                }
                --i;
            } else if (expression[i] != ':') {
                st.push(expression[i]);
            }
        }
        return string(1, st.top());
    }
};
