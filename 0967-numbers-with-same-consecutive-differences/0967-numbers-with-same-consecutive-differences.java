import java.util.*;
class Solution {
    public int[] numsSameConsecDiff(int n, int k) {
        if (n == 1) {
            int[] res = new int[10];
            for (int i = 0; i < 10; i++) res[i] = i;
            return res;
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i < 10; i++) {
            q.add(i);
        }
        for (int step = 0; step < n-1; step++) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.poll();
                int tail = num % 10;
                int[] nexts = {tail + k, tail - k};
                for (int d : nexts) {
                    if (d >= 0 && d <= 9) {
                        q.add(num*10 + d);
                    }
                }
            }
        }
        int[] res = new int[q.size()];
        int idx = 0;
        for (int v : q) {
            res[idx++] = v;
        }
        return res;
    }
}
