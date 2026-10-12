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
/**
 * Definition for a Node.
 * class Node {
 *     public int val;
 *     public vector<Node*> children;
 *     public Node() {}
 *     public Node(int _val) { val = _val; }
 *     public Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
 * };
 */
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }
        vector<string> ans;
        int leastIndex = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (map.find(list2[i]) != map.end()) {
                int idx = map[list2[i]] + i;
                if (idx < leastIndex) {
                    leastIndex = idx;
                    ans.clear();
                    ans.push_back(list2[i]);
                } else if (idx == leastIndex) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
