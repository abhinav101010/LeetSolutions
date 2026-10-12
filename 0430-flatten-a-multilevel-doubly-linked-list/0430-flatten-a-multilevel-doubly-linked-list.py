# Definition for a Node.
# class Node:
#     def __init__(self, val, prev, next, child):
#         self.val = val
#         self.prev = prev
#         self.next = next
#         self.child = child

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head:
            return None
        
        def dfs(node):
            curr = node
            last = node
            while curr:
                next_node = curr.next
                if curr.child:
                    child_last = dfs(curr.child)
                    curr.next = curr.child
                    curr.child.prev = curr
                    child_last.next = next_node
                    if next_node:
                        next_node.prev = child_last
                    curr.child = None
                    last = child_last
                else:
                    last = curr
                curr = next_node
            return last
        
        dfs(head)
        return head