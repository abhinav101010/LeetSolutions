class Solution {
    public int minElement(int[] nums) {
        int m = Integer.MAX_VALUE;
        for (int x : nums) m = Math.min(m, x);
        int s = 0;
        while (m > 0) { s += m % 10; m /= 10; }
        return s;
    }
}
