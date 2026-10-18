class Solution:
    def maximumAverageSubtree(self, root):
        self.best=0
        def dfs(n):
            if not n: return (0,0)
            ls,lc=dfs(n.left); rs,rc=dfs(n.right)
            s=n.val+ls+rs; c=1+lc+rc
            self.best=max(self.best,s/c)
            return s,c
        dfs(root); return self.best
