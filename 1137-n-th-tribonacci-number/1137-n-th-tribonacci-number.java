class Solution {
    public int tribonacci(int n) {
        int a = 0, b = 1, c = 1;

        for (int i = 0; i < n; i++) {
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }

        return a;
    }
}