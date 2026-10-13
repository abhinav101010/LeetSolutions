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
    public ListNode plusOne(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode lastNotNine = dummy;
        ListNode cur = head;
        while (cur != null) {
            if (cur.val != 9) {
                lastNotNine = cur;
            }
            cur = cur.next;
        }
        lastNotNine.val += 1;
        cur = lastNotNine.next;
        while (cur != null) {
            cur.val = 0;
            cur = cur.next;
        }
        return dummy.val == 0 ? dummy.next : dummy;
    }
}