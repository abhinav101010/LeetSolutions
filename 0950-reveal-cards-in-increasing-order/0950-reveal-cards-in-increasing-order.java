import java.util.Arrays;
import java.util.Deque;
import java.util.ArrayDeque;
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Arrays.sort(deck);
        int[] res = new int[n];
        Deque<Integer> idx = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            idx.add(i);
        }
        int pos = 0;
        for (int card : deck) {
            int i = idx.pollFirst();
            res[i] = card;
            if (!idx.isEmpty()) {
                idx.addLast(idx.pollFirst());
            }
        }
        return res;
    }
}
