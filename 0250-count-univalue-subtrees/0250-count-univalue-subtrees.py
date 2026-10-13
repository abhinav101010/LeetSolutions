class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        self.count = 0
        
        def is_unival(node):
            if not node:
                return True
            left = is_unival(node.left)
            right = is_unival(node.right)
            if left and right:
                if (not node.left or node.left.val == node.val) and (not node.right or node.right.val == node.val):
                    self.count += 1
                    return True
            return False
        
        is_unival(root)
        return self.count