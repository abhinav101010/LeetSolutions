class Solution:
    def btreeGameWinningMove(self, root, n, x):
        self.sizes=[0,0]
        def dfs(node):
            if not node: return 0
            l=dfs(node.left); r=dfs(node.right)
            if node.val==x: self.sizes=[l,r]
            return l+r+1
        dfs(root)
        parent=n-1-self.sizes[0]-self.sizes[1]
        return max(self.sizes[0],self.sizes[1],parent)>n//2
