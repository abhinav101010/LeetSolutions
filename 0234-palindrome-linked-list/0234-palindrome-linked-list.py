# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        l, r = 0, len(vals) - 1
        while l < r:
            if vals[l] != vals[r]:
                return False
            l += 1
            r -= 1
        return True
