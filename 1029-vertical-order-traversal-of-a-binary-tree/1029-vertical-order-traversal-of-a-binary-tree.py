# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict, deque
class Solution:
    def verticalTraversal(self, root: TreeNode) -> list[list[int]]:
        if not root: return []
        res = defaultdict(lambda: defaultdict(list))
        q = deque([(root, 0, 0)]) # (node, col, row)
        while q:
            node, col, row = q.popleft()
            res[col][row].append(node.val)
            if node.left: q.append((node.left, col-1, row+1))
            if node.right: q.append((node.right, col+1, row+1))
        ans = []
        for col in sorted(res):
            col_res = []
            for row in sorted(res[col]):
                col_res.extend(sorted(res[col][row]))
            ans.append(col_res)
        return ans
