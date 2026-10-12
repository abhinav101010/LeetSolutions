import java.util.*;

class Solution {
    public int findNthDigit(int n) {
        long length = 1, count = 9, start = 1;
        long nLong = n;
        
        while (nLong > length * count) {
            nLong -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }
        
        start += (nLong - 1) / length;
        String s = String.valueOf(start);
        return s.charAt((int)((nLong - 1) % length)) - '0';
    }
}