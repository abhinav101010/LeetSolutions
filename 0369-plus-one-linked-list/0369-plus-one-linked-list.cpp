/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* lastNotNine = dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->val != 9) {
                lastNotNine = cur;
            }
            cur = cur->next;
        }
        lastNotNine->val += 1;
        cur = lastNotNine->next;
        while (cur) {
            cur->val = 0;
            cur = cur->next;
        }
        if (dummy->val == 0) return dummy->next;
        else return dummy;
    }
};