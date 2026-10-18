class Solution {
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> s=new HashSet<>();
        for(int x:to_delete) s.add(x);
        List<TreeNode> res=new ArrayList<>();
        dfs(root,true,s,res);
        return res;
    }
    TreeNode dfs(TreeNode node,boolean isRoot,Set<Integer> s,List<TreeNode> res){
        if(node==null) return null;
        boolean del=s.contains(node.val);
        if(isRoot && !del) res.add(node);
        node.left=dfs(node.left,del,s,res);
        node.right=dfs(node.right,del,s,res);
        return del?null:node;
    }
}