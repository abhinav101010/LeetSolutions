struct ListNode {
    int val; ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        ListNode* cur = head;
        while (cur) { vals.push_back(cur->val); cur = cur->next; }
        int n = vals.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vals[st.top()] < vals[i]) { res[st.top()] = vals[i]; st.pop(); }
            st.push(i);
        }
        return res;
    }
};
