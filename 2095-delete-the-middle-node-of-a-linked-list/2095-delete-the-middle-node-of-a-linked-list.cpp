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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        if (length == 1) return nullptr;
        temp = head;
        for (int i = 0; i < length / 2; i++) {
            if (i == (length / 2) - 1) {
                if (temp->next) {
                    temp->next = temp->next->next;
                }
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};