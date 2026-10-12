/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;
    public int maxDepth(TreeNode root) {
        count(root, 1);
        return ans;
    }

    public void count(TreeNode root, int i){
        if(root == null){
            return;
        }
        ans = (i>ans)? i : ans;
        count(root.left, i+1);
        count(root.right, i+1);
    }
}