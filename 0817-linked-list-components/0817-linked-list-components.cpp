// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int count = 0;
        bool prevIn = false;
        ListNode* curr = head;
        while (curr != nullptr) {
            bool in = set.find(curr->val) != set.end();
            if (in && !prevIn) {
                count++;
            }
            prevIn = in;
            curr = curr->next;
        }
        return count;
    }
};
