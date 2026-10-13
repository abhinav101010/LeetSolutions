class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        
        def dfs(node, parent_val, length):
            if not node:
                return
            if parent_val + 1 == node.val:
                length += 1
            else:
                length = 1
            self.res = max(self.res, length)
            dfs(node.left, node.val, length)
            dfs(node.right, node.val, length)
        
        dfs(root, None, 0)
        return self.res