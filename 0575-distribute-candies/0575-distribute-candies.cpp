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
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> unique(candyType.begin(), candyType.end());
        int uniqueCount = unique.size();
        return uniqueCount <= n / 2 ? uniqueCount : n / 2;
    }
};
