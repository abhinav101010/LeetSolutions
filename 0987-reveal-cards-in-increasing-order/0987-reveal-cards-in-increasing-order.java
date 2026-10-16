import java.util.*;
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Arrays.sort(deck);
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) q.addLast(i);
        int[] ans = new int[n];
        for (int card : deck) {
            int idx = q.pollFirst();
            ans[idx] = card;
            if (!q.isEmpty()) {
                q.addLast(q.pollFirst());
            }
        }
        return ans;
    }
}
