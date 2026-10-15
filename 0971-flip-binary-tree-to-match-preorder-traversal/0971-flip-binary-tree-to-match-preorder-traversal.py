# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: list[int]) -> list[int]:
        self.ans = []
        self.i = 0
        def dfs(node):
            if not node:
                return True
            if node.val != voyage[self.i]:
                self.ans = [-1]
                return False
            self.i += 1
            if self.i == len(voyage):
                return True
            # if left exists and matches next, continue; else try flip
            if node.left and node.left.val == voyage[self.i]:
                if not dfs(node.left):
                    return False
                if not dfs(node.right):
                    return False
            else:
                # need to flip
                if node.right:
                    self.ans.append(node.val)
                if not dfs(node.right):
                    return False
                if not dfs(node.left):
                    return False
            return True
        if dfs(root):
            return self.ans
        else:
            return [-1]
