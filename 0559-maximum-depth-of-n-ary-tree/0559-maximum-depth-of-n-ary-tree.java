/**
 * Definition for a Node.
 * class Node {
 *     public int val;
 *     public List<Node> children;
 *     public Node() {}
 *     public Node(int _val) { val = _val; }
 *     public Node(int _val, List<Node> _children) { val = _val; children = _children; }
 * };
 */

class Solution {
    private int ans = 0;

    private void dfs(Node root, int curr) {
        if (root == null) {
            return;
        }
        if (curr > ans) {
            ans = curr;
        }
        if (root.children != null) {
            for (Node child : root.children) {
                dfs(child, curr + 1);
            }
        }
    }

    public int maxDepth(Node root) {
        ans = 0;
        dfs(root, 1);
        return ans;
    }
}