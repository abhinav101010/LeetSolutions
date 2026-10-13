class Solution:
    def inorderSuccessor(self, root: Optional[TreeNode], p: Optional[TreeNode]) -> Optional[TreeNode]:
        res = None
        while root:
            if root.val > p.val:
                res = root
                root = root.left
            else:
                root = root.right
        return res