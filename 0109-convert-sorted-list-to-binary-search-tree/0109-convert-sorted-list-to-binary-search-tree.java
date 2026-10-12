/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

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
    private ListNode node;

    public TreeNode sortedListToBST(ListNode head) {
        node = head;
        int size = 0;
        while (node != null) {
            size++;
            node = node.next;
        }
        node = head;
        return build(0, size - 1);
    }

    TreeNode build(int left, int right) {
        if (left > right) {
            return null;
        }

        int mid = left + (right - left) / 2;

        TreeNode leftChild = build(left, mid - 1);
        TreeNode root = new TreeNode(node.val);
        root.left = leftChild;
        node = node.next;
        root.right = build(mid + 1, right);
        return root;
    }
}
