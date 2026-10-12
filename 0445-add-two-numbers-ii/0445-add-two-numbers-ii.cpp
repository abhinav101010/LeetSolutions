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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> stack1, stack2;
        while (l1) {
            stack1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stack2.push_back(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* head = nullptr;
        while (!stack1.empty() || !stack2.empty() || carry) {
            int sum = carry;
            if (!stack1.empty()) {
                sum += stack1.back();
                stack1.pop_back();
            }
            if (!stack2.empty()) {
                sum += stack2.back();
                stack2.pop_back();
            }
            
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        
        return head;
    }
};