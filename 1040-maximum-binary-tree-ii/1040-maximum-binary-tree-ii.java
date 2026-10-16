class TreeNode {
    int val; TreeNode left,right;
    TreeNode(){} TreeNode(int v){val=v;}
    TreeNode(int v,TreeNode l,TreeNode r){val=v;left=l;right=r;}
}
class Solution {
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root == null || val > root.val) {
            return new TreeNode(val, root, null);
        }
        root.right = insertIntoMaxTree(root.right, val);
        return root;
    }
}
