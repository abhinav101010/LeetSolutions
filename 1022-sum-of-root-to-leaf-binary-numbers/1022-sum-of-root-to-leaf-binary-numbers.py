# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def generate(s, root):
            nonlocal ans
            if not root:
                return

            s += str(root.val)
            if not root.left and not root.right:
                ans += int(s, 2)
                return

            generate(s, root.left)
            generate(s, root.right)
            
        generate("", root)
        return ans

