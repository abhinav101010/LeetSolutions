import java.time.LocalDate;

class Solution {
    public int daysBetweenDates(String date1, String date2) {
        LocalDate d1 = LocalDate.parse(date1);
        LocalDate d2 = LocalDate.parse(date2);
        return Math.abs((int) d1.until(d2).getDays());
    }
}