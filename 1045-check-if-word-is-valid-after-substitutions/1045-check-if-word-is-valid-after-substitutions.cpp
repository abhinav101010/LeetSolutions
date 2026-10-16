#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        for (char c : S) {
            if (c == 'c') {
                if (st.size() < 2 || st.top() != 'b') return false;
                st.pop();
                if (st.top() != 'a') return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
