# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
# Self thought and implemented but gives tle
        # dummy = ListNode(0)
        # curr = head

        # while curr:
        #     prev = dummy

        #     while prev.next and prev.next.val < curr.val:
        #         prev = prev.next

        #     nxt = curr.next

        #     curr.next = prev.next
        #     prev.next = curr

        #     curr = nxt

        # return dummy.next

        if not head or not head.next:
            return head

        # Find middle
        slow = head
        fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # Split list
        second = slow.next
        slow.next = None

        # Sort both halves
        left = self.sortList(head)
        right = self.sortList(second)

        # Merge
        dummy = ListNode(0)
        curr = dummy

        while left and right:
            if left.val < right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next

            curr = curr.next

        if left:
            curr.next = left
        else:
            curr.next = right

        return dummy.next