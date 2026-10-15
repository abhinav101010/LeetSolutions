import java.util.*;
class Solution {
    public int oddEvenJumps(int[] arr) {
        int n = arr.length;
        int[] nextHigher = new int[n];
        int[] nextLower = new int[n];
        // next higher
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> {
            if (arr[a] != arr[b]) return Integer.compare(arr[a], arr[b]);
            return Integer.compare(a, b);
        });
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i : indices) {
            while (!stack.isEmpty() && i > stack.peek()) {
                nextHigher[stack.pop()] = i;
            }
            stack.push(i);
        }
        // next lower
        Arrays.sort(indices, (a, b) -> {
            if (arr[a] != arr[b]) return Integer.compare(arr[b], arr[a]); // descending
            return Integer.compare(a, b);
        });
        stack.clear();
        for (int i : indices) {
            while (!stack.isEmpty() && i > stack.peek()) {
                nextLower[stack.pop()] = i;
            }
            stack.push(i);
        }
        // dp
        boolean[] odd = new boolean[n];
        boolean[] even = new boolean[n];
        odd[n-1] = even[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            odd[i] = even[nextHigher[i]];
            even[i] = odd[nextLower[i]];
        }
        int ans = 0;
        for (boolean b : odd) if (b) ans++;
        return ans;
    }
}
