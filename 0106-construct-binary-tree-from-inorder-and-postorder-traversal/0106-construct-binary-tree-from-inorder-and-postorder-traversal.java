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
import java.util.*;

class Solution {
    private int[] inorder;
    private int[] postorder;
    private Map<Integer, Integer> inIndex = new HashMap<>();
    private int postPos;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.inorder = inorder;
        this.postorder = postorder;
        this.postPos = postorder.length - 1;

        for (int i = 0; i < inorder.length; i++) {
            inIndex.put(inorder[i], i);
        }

        return build(0, inorder.length - 1);
    }

    private TreeNode build(int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }

        int rootVal = postorder[postPos--];
        TreeNode root = new TreeNode(rootVal);
        int mid = inIndex.get(rootVal);

        root.right = build(mid + 1, inEnd);
        root.left = build(inStart, mid - 1);

        return root;
    }
}
