# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head):
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        n = len(vals)
        res = [0]*n
        stack = []
        for i, v in enumerate(vals):
            while stack and vals[stack[-1]] < v:
                res[stack.pop()] = v
            stack.append(i)
        return res
