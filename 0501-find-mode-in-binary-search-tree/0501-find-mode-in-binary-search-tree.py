# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        count = {}

        def dfs(root):
            if not root:
                return
            count[root.val] = count.get(root.val, 0) + 1
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        maxCount = max(count.values())
        return [num for num in count if count[num] == maxCount]
