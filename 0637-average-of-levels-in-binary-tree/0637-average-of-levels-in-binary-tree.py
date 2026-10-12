# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        levels = {}

        def recurr(root, level):
            if not root:
                return

            if level not in levels:
                levels[level] = []

            levels[level].append(root.val)

            recurr(root.left, level + 1)
            recurr(root.right, level + 1)

        recurr(root, 0)

        ans = []

        for value in levels.values():
            ans.append(sum(value) / len(value))

        return ans