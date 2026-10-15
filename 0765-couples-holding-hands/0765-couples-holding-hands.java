import java.util.*;

class Solution {
    public int minSwapsCouples(int[] row) {
        int n = row.length;
        int[] dsu = new int[n/2];
        for (int i = 0; i < n/2; i++) dsu[i] = i;
        java.util.function.Function<Integer, Integer> find = x -> {
            while (dsu[x] != x) {
                dsu[x] = dsu[dsu[x]];
                x = dsu[x];
            }
            return x;
        };
        java.util.function.BiConsumer<Integer, Integer> union = (a, b) -> {
            int ra = find.apply(a);
            int rb = find.apply(b);
            if (ra != rb) {
                dsu[ra] = rb;
            }
        };
        for (int i = 0; i < n; i += 2) {
            int a = row[i] / 2;
            int b = row[i+1] / 2;
            union.accept(a, b);
        }
        Set<Integer> roots = new HashSet<>();
        for (int i = 0; i < n/2; i++) {
            roots.add(find.apply(i));
        }
        return (n/2) - roots.size();
    }
}
