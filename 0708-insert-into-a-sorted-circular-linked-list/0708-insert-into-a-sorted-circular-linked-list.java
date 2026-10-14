// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node() {}
    public Node(int _val) {
        val = _val;
    }
    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
}

class Solution {
    public Node insert(Node head, int insertVal) {
        if (head == null) {
            Node node = new Node(insertVal);
            node.next = node;
            return node;
        }
        Node prev = head;
        Node curr = head.next;
        while (true) {
            if (prev.val <= insertVal && insertVal <= curr.val) {
                break;
            }
            if (prev.val > curr.val) {
                if (insertVal >= prev.val || insertVal <= curr.val) {
                    break;
                }
            }
            prev = curr;
            curr = curr.next;
            if (prev == head) {
                break;
            }
        }
        Node newNode = new Node(insertVal);
        prev.next = newNode;
        newNode.next = curr;
        return head;
    }
}
