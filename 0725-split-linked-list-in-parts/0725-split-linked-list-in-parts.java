import java.util.*;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        ListNode cur = head;
        while (cur != null) {
            n++;
            cur = cur.next;
        }
        int baseSize = n / k;
        int extra = n % k;
        ListNode[] res = new ListNode[k];
        cur = head;
        for (int i = 0; i < k; i++) {
            res[i] = cur;
            int partSize = baseSize + (i < extra ? 1 : 0);
            for (int j = 0; j < partSize - 1; j++) {
                if (cur != null) {
                    cur = cur.next;
                }
            }
            if (cur != null) {
                ListNode next = cur.next;
                cur.next = null;
                cur = next;
            }
        }
        return res;
    }
}
