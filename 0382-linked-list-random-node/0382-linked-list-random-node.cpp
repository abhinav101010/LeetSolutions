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
private:
    ListNode* head;
    
public:
    Solution(ListNode* head) : head(head) {}
    
    int getRandom() {
        int result = head->val;
        ListNode* curr = head->next;
        int i = 2;
        while (curr) {
            if (rand() % i == 0) {
                result = curr->val;
            }
            curr = curr->next;
            i++;
        }
        return result;
    }
};