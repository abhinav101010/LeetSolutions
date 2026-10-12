# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = {}
        def sortLevels(curr, level):
            if not curr:
                return
            
            if level in levels:
                levels[level].append(curr.val)
            else:
                levels[level] = [curr.val]
            
            sortLevels(curr.left, level+1)
            sortLevels(curr.right, level+1)
        sortLevels(root, 1)
        return list(levels.values())