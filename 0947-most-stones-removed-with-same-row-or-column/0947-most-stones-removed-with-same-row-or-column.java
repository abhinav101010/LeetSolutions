import java.util.*;
class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        int[] parent = new int[20002]; // 0..10000 for rows, 10001..20001 for cols
        for (int i = 0; i < parent.length; i++) parent[i] = i;
        java.util.function.IntUnaryOperator find = x -> {
            int root = x;
            while (parent[root] != root) {
                root = parent[root];
            }
            while (x != root) {
                int next = parent[x];
                parent[x] = root;
                x = next;
            }
            return root;
        };
        java.util.function.BiConsumer<Integer, Integer> union = (a, b) -> {
            int ra = find.applyAsInt(a);
            int rb = find.applyAsInt(b);
            if (ra != rb) {
                parent[rb] = ra;
            }
        };
        for (int[] stone : stones) {
            int x = stone[0];
            int y = stone[1];
            union.accept(x, y + 10001);
        }
        Set<Integer> roots = new HashSet<>();
        for (int[] stone : stones) {
            int x = stone[0];
            roots.add(find.applyAsInt(x));
        }
        return n - roots.size();
    }
}
