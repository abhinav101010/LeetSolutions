# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        dummy = ListNode()
        tempNewList = dummy

        while temp:
            # Current node is unique
            if not temp.next or temp.val != temp.next.val:
                tempNewList.next = ListNode(temp.val)
                tempNewList = tempNewList.next
                temp = temp.next

            # Current node starts a duplicate block
            else:
                while temp.next and temp.val == temp.next.val:
                    temp = temp.next
                temp = temp.next
        return dummy.next