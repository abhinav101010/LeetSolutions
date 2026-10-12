# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        length = 0
        tempHead = head
        while tempHead:
            tempHead = tempHead.next
            length+=1
        
        tempHead = head
        reversedList = None
        for i in range(1, length+1):
            if left <= i <= right:
                reversedList = ListNode(tempHead.val, reversedList)
            if i > right: break
            tempHead = tempHead.next

        suffix = tempHead

        tail = reversedList
        while tail.next:
            tail = tail.next
        tail.next = suffix

        if left == 1:
            return reversedList
            
        temp = head
        for _ in range(left - 2):
            temp = temp.next
        temp.next = reversedList
        return head
