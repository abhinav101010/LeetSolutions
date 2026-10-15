import java.util.*;
import java.math.BigInteger;
class Solution {
    public List<Integer> splitIntoFibonacci(String num) {
        int n = num.length();
        for (int i = 1; i <= Math.min(10, n-1); i++) {
            if (num.charAt(0) == '0' && i > 1) break;
            long first = Long.parseLong(num.substring(0, i));
            if (first > Integer.MAX_VALUE) break;
            for (int j = i+1; j <= Math.min(n, i+10); j++) {
                if (num.charAt(i) == '0' && j-i > 1) break;
                long second = Long.parseLong(num.substring(i, j));
                if (second > Integer.MAX_VALUE) break;
                List<Integer> seq = new ArrayList<>();
                seq.add((int) first);
                seq.add((int) second);
                int k = j;
                while (k < n) {
                    long third = (long) seq.get(seq.size()-1) + (long) seq.get(seq.size()-2);
                    if (third > Integer.MAX_VALUE) break;
                    String thirdStr = Long.toString(third);
                    if (num.startsWith(thirdStr, k)) {
                        seq.add((int) third);
                        k += thirdStr.length();
                    } else {
                        break;
                    }
                }
                if (k == n && seq.size() >= 3) {
                    return seq;
                }
            }
        }
        return new ArrayList<>();
    }
}
