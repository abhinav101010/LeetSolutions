class Solution {
    public int dayOfYear(String date) {
        String[] parts = date.split("-");
        int year = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int day = Integer.parseInt(parts[2]);

        int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        boolean leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

        int ans = 0;
        for (int i = 1; i < month; i++) {
            ans += days[i];
        }
        ans += day;

        if (leap && month > 2) {
            ans++;
        }

        return ans;
    }
}