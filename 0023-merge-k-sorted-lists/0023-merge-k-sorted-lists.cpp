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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < (int)lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, i});
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            int i = pq.top().second;
            pq.pop();
            curr->next = lists[i];
            curr = lists[i];
            lists[i] = lists[i]->next;
            if (lists[i]) {
                pq.push({lists[i]->val, i});
            }
        }

        return dummy.next;
    }
};
