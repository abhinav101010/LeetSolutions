#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        vector<char> ops {'*','/','+','-'};
        stack<int> st;
        st.push(N);
        int op = 1;
        for (int i = N-1; i >= 1; i--) {
            char o = ops[(op-1)%4];
            if (o == '*') {
                int top = st.top(); st.pop();
                st.push(top * i);
            } else if (o == '/') {
                int top = st.top(); st.pop();
                st.push(top / i);
            } else if (o == '+') {
                st.push(i);
            } else {
                st.push(-i);
            }
            op++;
        }
        int res = 0;
        while (!st.empty()) { res += st.top(); st.pop(); }
        return res;
    }
};
