/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        ListNode temp = head;
        int length = 0;
        while (temp != null) {
            length++;
            temp = temp.next;
        }
        if (length == 1) return null;
        temp = head;
        for (int i = 0; i < length / 2; i++) {
            if (i == (length / 2) - 1) {
                if (temp.next != null) {
                    temp.next = temp.next.next;
                }
                break;
            }
            temp = temp.next;
        }
        return head;
    }
}