class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        int[] boxes = new int[100001];
        int max = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0;
            int num = i;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            boxes[sum]++;
            max = Math.max(max, boxes[sum]);
        }

        return max;
    }
}