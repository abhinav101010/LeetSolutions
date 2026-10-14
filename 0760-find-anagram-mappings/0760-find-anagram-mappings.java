import java.util.*;

class Solution {
    public List<Integer> anagramMappings(int[] A, int[] B) {
        Map<Integer, Deque<Integer>> map = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            map.computeIfAbsent(B[i], k -> new ArrayDeque<>()).addLast(i);
        }
        List<Integer> res = new ArrayList<>();
        for (int val : A) {
            res.add(map.get(val).removeFirst());
        }
        return res;
    }
}
