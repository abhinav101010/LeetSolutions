class Solution {
    public String reformatDate(String date) {
        String[] parts = date.split(" ");
        String day = parts[0];
        String month = parts[1];
        String year = parts[2];

        String[] months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int monthNum = 0;
        for (int i = 0; i < months.length; i++) {
            if (months[i].equals(month)) {
                monthNum = i + 1;
                break;
            }
        }

        int dayNum = 0;
        for (int i = 0; i < day.length(); i++) {
            char c = day.charAt(i);
            if (c >= '0' && c <= '9') {
                dayNum = dayNum * 10 + (c - '0');
            } else {
                break;
            }
        }

        return String.format("%s-%02d-%02d", year, monthNum, dayNum);
    }
}