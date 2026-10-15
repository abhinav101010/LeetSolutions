class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution {
    public TreeNode[] splitBST(TreeNode root, int target) {
        if (root == null) {
            return new TreeNode[]{null, null};
        }
        if (root.val <= target) {
            TreeNode[] rightSplit = splitBST(root.right, target);
            root.right = rightSplit[0];
            TreeNode[] res = new TreeNode[2];
            res[0] = root;
            res[1] = rightSplit[1];
            return res;
        } else {
            TreeNode[] leftSplit = splitBST(root.left, target);
            root.left = leftSplit[1];
            TreeNode[] res = new TreeNode[2];
            res[0] = leftSplit[0];
            res[1] = root;
            return res;
        }
    }
}
