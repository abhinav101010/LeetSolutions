// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <vector>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        int baseSize = n / k;
        int extra = n % k;
        vector<ListNode*> res(k, nullptr);
        cur = head;
        for (int i = 0; i < k; i++) {
            res[i] = cur;
            int partSize = baseSize + (i < extra ? 1 : 0);
            for (int j = 0; j < partSize - 1; j++) {
                if (cur) cur = cur->next;
            }
            if (cur) {
                ListNode* next = cur->next;
                cur->next = nullptr;
                cur = next;
            }
        }
        return res;
    }
};
