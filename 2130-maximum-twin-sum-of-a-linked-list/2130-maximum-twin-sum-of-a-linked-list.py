# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        temp = head
        length=0
        while temp:
            length+=1
            temp = temp.next
            
        temp = head
        ans = {}
        for i in range(length):
            if i <= (length//2):
                ans.update({i:temp.val})
            if i >= (length//2):
                ans[length-1-i] += temp.val
            temp = temp.next
        return max(ans.values())