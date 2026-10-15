# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def numComponents(self, head: ListNode, nums: list[int]) -> int:
        set_nums = set(nums)
        count = 0
        curr = head
        prev_in_set = False
        while curr:
            if curr.val in set_nums:
                if not prev_in_set:
                    count += 1
                prev_in_set = True
            else:
                prev_in_set = False
            curr = curr.next
        return count
