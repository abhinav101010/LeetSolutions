# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        tempHead = head
        length = 0
        while tempHead:
            length += 1
            tempHead = tempHead.next

        k %= length
        if k == 0:
            return head

        # Find the node before the new head
        split = length - k
        tempHead = head

        for _ in range(split - 1):
            tempHead = tempHead.next

        newHead = tempHead.next
        tempHead.next = None

        # Find the tail of the second part
        tail = newHead
        while tail.next:
            tail = tail.next

        # Attach the first part
        tail.next = head

        return newHead