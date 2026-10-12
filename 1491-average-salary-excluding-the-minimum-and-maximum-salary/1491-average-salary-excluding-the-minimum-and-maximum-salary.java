class Solution {
    public double average(int[] salary) {
        int sum = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        for (int s : salary) {
            sum += s;
            if (s < min) {
                min = s;
            }
            if (s > max) {
                max = s;
            }
        }

        return (double) (sum - min - max) / (salary.length - 2);
    }
}