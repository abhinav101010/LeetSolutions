#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverse(ListNode* head, int l) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* tail = cur;
        int i = 0;
        while (cur && i < l) {
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
            ++i;
        }
        tail->next = cur;
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int n = 0;
        for (ListNode* t = head; t; t = t->next) ++n;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        int l = 1;
        while ((1 + l) * l / 2 <= n && prev) {
            if (l % 2 == 0) {
                prev->next = reverse(prev->next, l);
            }
            for (int i = 0; i < l && prev; ++i) prev = prev->next;
            ++l;
        }
        int left = n - l * (l - 1) / 2;
        if (left > 0 && left % 2 == 0) {
            prev->next = reverse(prev->next, left);
        }
        return dummy.next;
    }
};
