class Solution:
    def plusOne(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        last_not_nine = dummy
        cur = head
        while cur:
            if cur.val != 9:
                last_not_nine = cur
            cur = cur.next
        last_not_nine.val += 1
        cur = last_not_nine.next
        while cur:
            cur.val = 0
            cur = cur.next
        return dummy if dummy.val else dummy.next