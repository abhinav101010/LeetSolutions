import java.util.*;
class Solution {
    public int oddEvenJumps(int[] arr) {
        int n = arr.length;
        int[] nextHigher = new int[n];
        int[] nextLower = new int[n];
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        Arrays.sort(idx, (a,b) -> arr[a] != arr[b] ? Integer.compare(arr[a], arr[b]) : Integer.compare(a,b));
        Deque<Integer> st = new ArrayDeque<>();
        for (int i : idx) {
            while (!st.isEmpty() && i > st.peek()) nextHigher[st.pop()] = i;
            st.push(i);
        }
        Arrays.sort(idx, (a,b) -> arr[a] != arr[b] ? Integer.compare(arr[b], arr[a]) : Integer.compare(a,b));
        st.clear();
        for (int i : idx) {
            while (!st.isEmpty() && i > st.peek()) nextLower[st.pop()] = i;
            st.push(i);
        }
        boolean[] odd = new boolean[n], even = new boolean[n];
        odd[n-1] = even[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            odd[i] = even[nextHigher[i]];
            even[i] = odd[nextLower[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) if (odd[i]) ans++;
        return ans;
    }
}
