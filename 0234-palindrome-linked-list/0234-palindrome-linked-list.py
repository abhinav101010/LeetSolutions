# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # dummy = None
        # temp = head
        # while temp:
        #     dummy = ListNode(temp.val, dummy)
        #     temp = temp.next
        
        # temp = head
        # while temp:
        #     if temp.val != dummy.val:
        #         return False
        #     temp = temp.next
        #     dummy = dummy.next
        # return True

        l=[]
        t=head
        while t:
            l.append(t.val)
            t=t.next
        return l==l[::-1]