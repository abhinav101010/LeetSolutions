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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        if (restrictions.empty() || restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        sort(restrictions.begin(), restrictions.end());

        for (int i = 1; i < restrictions.size(); ++i) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }

        for (int i = restrictions.size() - 2; i >= 0; --i) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }

        int ans = 0;
        for (int i = 1; i < restrictions.size(); ++i) {
            int x1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int x2 = restrictions[i][0], h2 = restrictions[i][1];
            int dist = x2 - x1;
            int peak = (h1 + h2 + dist) / 2;
            ans = max(ans, peak);
        }
        return ans;
    }
};