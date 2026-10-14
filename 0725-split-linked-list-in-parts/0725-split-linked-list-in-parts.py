# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import List, Optional

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        # compute length
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next
        base_size = n // k
        extra = n % k  # number of parts that get an extra node
        res: List[Optional[ListNode]] = []
        cur = head
        for i in range(k):
            head_part = cur
            part_size = base_size + (1 if i < extra else 0)
            for _ in range(part_size - 1):
                if cur:
                    cur = cur.next
            if cur:
                nxt = cur.next
                cur.next = None
                cur = nxt
            res.append(head_part)
        return res
