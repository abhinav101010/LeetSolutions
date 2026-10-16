import java.util.*;
class TreeNode {
    int val; TreeNode left,right;
    TreeNode(){} TreeNode(int v){val=v;}
    TreeNode(int v,TreeNode l,TreeNode r){val=v;left=l;right=r;}
}
class Solution {
    static class NodePos {
        TreeNode node; int col, row;
        NodePos(TreeNode n,int c,int r){node=n;col=c;row=r;}
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, List<Integer>>> res = new TreeMap<>();
        Queue<NodePos> q = new LinkedList<>();
        q.offer(new NodePos(root,0,0));
        while (!q.isEmpty()) {
            NodePos cur = q.poll();
            res.computeIfAbsent(cur.col, k->new TreeMap<>())
               .computeIfAbsent(cur.row, k->new ArrayList<>())
               .add(cur.node.val);
            if (cur.node.left != null) q.offer(new NodePos(cur.node.left, cur.col-1, cur.row+1));
            if (cur.node.right != null) q.offer(new NodePos(cur.node.right, cur.col+1, cur.row+1));
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (TreeMap<Integer,List<Integer>> rows : res.values()) {
            List<Integer> colList = new ArrayList<>();
            for (List<Integer> vals : rows.values()) {
                Collections.sort(vals);
                colList.addAll(vals);
            }
            ans.add(colList);
        }
        return ans;
    }
}
