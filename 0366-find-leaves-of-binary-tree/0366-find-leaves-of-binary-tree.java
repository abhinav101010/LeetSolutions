import java.util.*;

class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> findLeaves(TreeNode root) {
        getHeight(root);
        return res;
    }
    
    private int getHeight(TreeNode node) {
        if (node == null) return -1;
        int h = 1 + Math.max(getHeight(node.left), getHeight(node.right));
        while (res.size() <= h) {
            res.add(new ArrayList<>());
        }
        res.get(h).add(node.val);
        return h;
    }
}