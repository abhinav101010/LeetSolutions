import java.util.*;
class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for (int v : arr) set.add(v);
        int n = arr.length;
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = arr[i];
                int b = arr[j];
                int length = 2;
                while (set.contains(a + b)) {
                    int sum = a + b;
                    a = b;
                    b = sum;
                    length++;
                }
                if (length > best) {
                    best = length;
                }
            }
        }
        return best >= 3 ? best : 0;
    }
}
