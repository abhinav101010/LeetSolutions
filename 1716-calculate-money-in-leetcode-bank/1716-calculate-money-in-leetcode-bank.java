class Solution {
    public int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int total = 0;

        for (int week = 0; week < weeks; week++) {
            int start = week + 1;
            total += (start + start + 6) * 7 / 2;
        }

        int start = weeks + 1;
        for (int day = 0; day < days; day++) {
            total += start + day;
        }

        return total;
    }
}