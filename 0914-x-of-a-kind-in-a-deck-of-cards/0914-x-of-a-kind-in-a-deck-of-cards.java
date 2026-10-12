import java.util.*;

class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int card : deck) {
            count.put(card, count.getOrDefault(card, 0) + 1);
        }
        int x = 0;
        for (int freq : count.values()) {
            x = gcd(x, freq);
        }
        return x >= 2;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}