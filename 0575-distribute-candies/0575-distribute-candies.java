import java.util.HashSet;
import java.util.Set;

class Solution {
    public int distributeCandies(int[] candyType) {
        int n = candyType.length;
        Set<Integer> unique = new HashSet<Integer>();
        for (int c : candyType) {
            unique.add(c);
        }
        int uniqueCount = unique.size();
        return uniqueCount <= n / 2 ? uniqueCount : n / 2;
    }
}