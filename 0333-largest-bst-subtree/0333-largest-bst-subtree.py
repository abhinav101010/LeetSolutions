class Solution:
    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        
        def dfs(node):
            if not node:
                return True, 0, float('inf'), float('-inf')
            left_bst, left_size, left_min, left_max = dfs(node.left)
            right_bst, right_size, right_min, right_max = dfs(node.right)
            if left_bst and right_bst:
                if (not node.left or left_max < node.val) and (not node.right or right_min > node.val):
                    size = 1 + left_size + right_size
                    self.res = max(self.res, size)
                    min_val = left_min if node.left else node.val
                    max_val = right_max if node.right else node.val
                    return True, size, min_val, max_val
            return False, 0, 0, 0
        
        dfs(root)
        return self.res