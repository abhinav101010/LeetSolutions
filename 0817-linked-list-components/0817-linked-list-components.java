import java.util.*;
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
class Solution {
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int v : nums) set.add(v);
        int count = 0;
        boolean prevIn = false;
        ListNode curr = head;
        while (curr != null) {
            boolean in = set.contains(curr.val);
            if (in && !prevIn) {
                count++;
            }
            prevIn = in;
            curr = curr.next;
        }
        return count;
    }
}
