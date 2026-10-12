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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->next == nullptr || curr->val != curr->next->val) {
                tail->next = curr;
                tail = curr;
                curr = curr->next;
            } else {
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                curr = curr->next;
            }
        }

        tail->next = nullptr;
        return dummy->next;
    }
};
