# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructFromPrePost(self, pre: list[int], post: list[int]) -> TreeNode:
        index = {val: i for i, val in enumerate(post)}
        def helper(i1, i2, j1, j2) -> TreeNode:
            # pre[i1:i2] post[j1:j2] (i2 exclusive, j2 exclusive)
            if i1 >= i2:
                return None
            root = TreeNode(pre[i1])
            if i1 + 1 == i2:
                return root
            leftRootVal = pre[i1+1]
            leftPostIdx = index[leftRootVal]
            leftSize = leftPostIdx - j1 + 1
            root.left = helper(i1+1, i1+1+leftSize, j1, j1+leftSize)
            root.right = helper(i1+1+leftSize, i2, j1+leftSize, j2-1)
            return root
        return helper(0, len(pre), 0, len(post))
