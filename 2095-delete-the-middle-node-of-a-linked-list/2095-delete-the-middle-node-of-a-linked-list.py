# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        length = 0

        while temp:
            length += 1
            temp = temp.next

        if length == 1: return

        temp = head
        for i in range(length // 2):
            if i == (length // 2)-1:
                if temp.next:
                    temp.next = temp.next.next
                break
            temp = temp.next

        return head