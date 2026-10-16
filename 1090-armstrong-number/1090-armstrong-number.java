class Solution {
    public boolean isArmstrong(int N) {
        int t = N, k = 0;
        while (t > 0) { k++; t /= 10; }
        int sum = 0;
        t = N;
        while (t > 0) { sum += Math.pow(t%10, k); t /= 10; }
        return sum == N;
    }
}
