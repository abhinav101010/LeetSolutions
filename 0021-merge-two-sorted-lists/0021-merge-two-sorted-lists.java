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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        List<Integer> arr = new ArrayList<>();

        ListNode temp = list1;
        while(temp != null){
            arr.add(temp.val);
            temp = temp.next;
        }

        temp = list2;
        while(temp != null){
            arr.add(temp.val);
            temp = temp.next;
        }

        Collections.sort(arr);
        ListNode dummy = null;
        for (int i = arr.size() - 1; i >= 0; i--) {
            dummy = new ListNode(arr.get(i), dummy);
        }

        return dummy;
    }
}