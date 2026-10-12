class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] week = {
            "Friday", "Saturday", "Sunday",
            "Monday", "Tuesday", "Wednesday", "Thursday"
        };

        int[] days = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int total = 0;

        for (int y = 1971; y < year; y++) {
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
                total += 366;
            } else {
                total += 365;
            }
        }

        for (int m = 1; m < month; m++) {
            total += days[m - 1];
        }

        if (month > 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
            total += 1;
        }

        total += day - 1;

        return week[total % 7];
    }
}