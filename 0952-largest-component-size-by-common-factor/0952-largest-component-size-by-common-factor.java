import java.util.*;
class Solution {
    public int largestComponentSize(int[] A) {
        int n = A.length;
        int maxA = 0;
        for (int v : A) if (v > maxA) maxA = v;
        int[] parent = new int[maxA + 1];
        int[] size = new int[maxA + 1];
        for (int i = 0; i <= maxA; i++) {
            parent[i] = i;
            size[i] = 1;
        }
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
            if (ra == rb) return;
            if (size[ra] < size[rb]) {
                int temp = ra;
                ra = rb;
                rb = temp;
            }
            parent[rb] = ra;
            size[ra] += size[rb];
        };
        Map<Integer, Integer> primeToNum = new HashMap<>();
        for (int num : A) {
            int x = num;
            for (int t = 2; t * t <= x; t++) {
                if (x % t == 0) {
                    if (!primeToNum.containsKey(t)) {
                        primeToNum.put(t, num);
                    } else {
                        union.accept(num, primeToNum.get(t));
                    }
                    while (x % t == 0) {
                        x /= t;
                    }
                }
            }
            if (x > 1) {
                if (!primeToNum.containsKey(x)) {
                    primeToNum.put(x, num);
                } else {
                    union.accept(num, primeToNum.get(x));
                }
            }
        }
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : A) {
            int root = find.applyAsInt(num);
            count.put(root, count.getOrDefault(root, 0) + 1);
        }
        int ans = 0;
        for (int v : count.values()) {
            if (v > ans) ans = v;
        }
        return ans;
    }
}
