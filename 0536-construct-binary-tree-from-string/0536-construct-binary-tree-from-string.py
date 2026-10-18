import sys
sys.setrecursionlimit(10**7)

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if not s:
            return None
        stack = []
        i = 0
        while i < len(s):
            if s[i] == '(' or s[i] == ')':
                i += 1
                continue
            sign = 1
            if s[i] == '-' or s[i] == '+':
                sign = -1 if s[i] == '-' else 1
                i += 1
            num = 0
            while i < len(s) and s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1
            node = TreeNode(sign * num)
            if stack:
                parent = stack[-1]
                if parent.left is None:
                    parent.left = node
                else:
                    parent.right = node
            stack.append(node)
            if i < len(s) and s[i] == ')':
                stack.pop()
                i += 1
        return stack[-1] if stack else None
