class Solution:
    def lcaDeepestLeaves(self, root):
        def dfs(node):
            if not node: return (0,None)
            l=dfs(node.left); r=dfs(node.right)
            if l[0]>r[0]: return (l[0]+1,l[1])
            if r[0]>l[0]: return (r[0]+1,r[1])
            return (l[0]+1,node)
        return dfs(root)[1]