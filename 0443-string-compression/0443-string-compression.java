import java.util.*;

class Solution {
    public int compress(char[] chars) {
        int write = 0;
        int read = 0;
        int n = chars.length;
        
        while (read < n) {
            char c = chars[read];
            int count = 0;
            while (read < n && chars[read] == c) {
                read++;
                count++;
            }
            
            chars[write++] = c;
            
            if (count > 1) {
                for (char d : String.valueOf(count).toCharArray()) {
                    chars[write++] = d;
                }
            }
        }
        
        return write;
    }
}