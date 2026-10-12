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
    private int[] preorder;
    private Map<Integer, Integer> inIndex = new HashMap<>();
    private int prePos = 0;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.prePos = 0;
        this.inIndex = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            inIndex.put(inorder[i], i);
        }

        return build(0, inorder.length - 1);
    }

    private TreeNode build(int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }

        int rootVal = preorder[prePos++];
        TreeNode root = new TreeNode(rootVal);
        int mid = inIndex.get(rootVal);

        root.left = build(inStart, mid - 1);
        root.right = build(mid + 1, inEnd);

        return root;
    }
}
