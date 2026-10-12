# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = {}
        def checkLevel(root, level):
            if not root: return
            
            if level in levels:
                levels[level] += [root.val]
            else:
                levels[level] = [root.val]

            checkLevel(root.left, level+1)
            checkLevel(root.right, level+1)
            
        checkLevel(root, 0)
        return list(levels.values())[::-1]