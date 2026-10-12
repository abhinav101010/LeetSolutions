import java.util.*;

class Solution {
    private static final String[] BELOW_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private static final String[] TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    private static final String[] THOUSANDS = {"", "Thousand", "Million", "Billion"};
    
    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        
        StringBuilder result = new StringBuilder();
        for (int i = 0; num > 0; i++) {
            if (num % 1000 != 0) {
                result.insert(0, helper(num % 1000) + THOUSANDS[i] + " ");
            }
            num /= 1000;
        }
        
        return result.toString().trim();
    }
    
    private String helper(int n) {
        if (n == 0) return "";
        if (n < 20) return BELOW_20[n] + " ";
        if (n < 100) return TENS[n / 10] + " " + helper(n % 10);
        return BELOW_20[n / 100] + " Hundred " + helper(n % 100);
    }
}