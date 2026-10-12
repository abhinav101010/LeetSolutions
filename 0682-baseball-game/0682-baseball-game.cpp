#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for (const auto &op : ops) {
            if (op == "+") {
                int top = st.top(); st.pop();
                int newTop = top + st.top();
                st.push(top);
                st.push(newTop);
            } else if (op == "D") {
                st.push(st.top() * 2);
            } else if (op == "C") {
                st.pop();
            } else {
                st.push(stoi(op));
            }
        }
        int res = 0;
        while (!st.empty()) { res += st.top(); st.pop(); }
        return res;
    }
};