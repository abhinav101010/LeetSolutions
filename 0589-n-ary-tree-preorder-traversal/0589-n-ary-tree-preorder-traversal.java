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

import java.util.ArrayList;
import java.util.List;

class Solution {
    private void dfs(Node root, List<Integer> ans) {
        if (root == null) {
            return;
        }
        ans.add(root.val);
        if (root.children != null) {
            for (Node child : root.children) {
                dfs(child, ans);
            }
        }
    }

    public List<Integer> preorder(Node root) {
        List<Integer> ans = new ArrayList<Integer>();
        dfs(root, ans);
        return ans;
    }
}