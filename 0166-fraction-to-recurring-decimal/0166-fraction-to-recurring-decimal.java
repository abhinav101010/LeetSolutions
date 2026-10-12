import java.util.HashMap;
import java.util.Map;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        StringBuilder sb = new StringBuilder();
        long num = (long) numerator;
        long den = (long) denominator;
        if ((num < 0) ^ (den < 0)) sb.append("-");
        num = Math.abs(num);
        den = Math.abs(den);
        sb.append(num / den);
        long rem = num % den;
        if (rem == 0) return sb.toString();
        sb.append(".");
        Map<Long, Integer> seen = new HashMap<>();
        while (rem != 0) {
            if (seen.containsKey(rem)) {
                sb.insert(seen.get(rem), "(");
                sb.append(")");
                break;
            }
            seen.put(rem, sb.length());
            rem *= 10;
            sb.append(rem / den);
            rem %= den;
        }
        return sb.toString();
    }
}