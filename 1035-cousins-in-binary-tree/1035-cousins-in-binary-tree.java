import java.util.*;
class TreeNode {
    int val; TreeNode left,right;
    TreeNode(){} TreeNode(int v){val=v;}
    TreeNode(int v,TreeNode l,TreeNode r){val=v;left=l;right=r;}
}
class Solution {
    static class Pair {
        TreeNode node; int depth; int parentVal;
        Pair(TreeNode n,int d,int p){node=n;depth=d;parentVal=p;}
    }
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root,0,0));
        int px=-1,py=-1,dx=-1,dy=-1;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            if (cur.node.val == x) { px = cur.parentVal; dx = cur.depth; }
            if (cur.node.val == y) { py = cur.parentVal; dy = cur.depth; }
            if (px!=-1 && py!=-1) break;
            if (cur.node.left != null) q.offer(new Pair(cur.node.left, cur.depth+1, cur.node.val));
            if (cur.node.right != null) q.offer(new Pair(cur.node.right, cur.depth+1, cur.node.val));
        }
        return dx==dy && px!=py;
    }
}
