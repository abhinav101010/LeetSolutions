# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if not s:
            return None
        self.i = 0
        return self.dfs(s)
    
    def dfs(self, s):
        if self.i >= len(s):
            return None
        # parse number (could be negative)
        sign = 1
        if s[self.i] == '-':
            sign = -1
            self.i += 1
        num = 0
        while self.i < len(s) and s[self.i].isdigit():
            num = num * 10 + (ord(s[self.i]) - ord('0'))
            self.i += 1
        num *= sign
        node = TreeNode(num)
        # left child
        if self.i < len(s) and s[self.i] == '(':
            self.i += 1  # skip '('
            node.left = self.dfs(s)
            # after left subtree, we expect ')'
            if self.i < len(s) and s[self.i] == ')':
                self.i += 1  # skip ')'
        # right child
        if self.i < len(s) and s[self.i] == '(':
            self.i += 1  # skip '('
            node.right = self.dfs(s)
            if self.i < len(s) and s[self.i] == ')':
                self.i += 1  # skip ')'
        return node
