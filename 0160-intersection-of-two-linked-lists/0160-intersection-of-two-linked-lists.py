# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        temp = headA
        seen = set()
        while temp:
            seen.add(temp)
            temp = temp.next

        temp = headB
        while temp:
            if temp in seen:
                return temp
            temp = temp.next