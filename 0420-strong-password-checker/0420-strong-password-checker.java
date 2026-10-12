import java.util.*;

class Solution {
    public int strongPasswordChecker(String password) {
        int n = password.length();
        int missingLower = 1, missingUpper = 1, missingDigit = 1;
        
        for (char c : password.toCharArray()) {
            if (Character.isLowerCase(c)) missingLower = 0;
            else if (Character.isUpperCase(c)) missingUpper = 0;
            else if (Character.isDigit(c)) missingDigit = 0;
        }
        
        int missingTypes = missingLower + missingUpper + missingDigit;
        
        if (n < 6) return Math.max(6 - n, missingTypes);
        
        int replace = 0, one = 0, two = 0;
        int i = 2;
        while (i < n) {
            if (password.charAt(i) == password.charAt(i-1) && password.charAt(i) == password.charAt(i-2)) {
                int length = 2;
                while (i < n && password.charAt(i) == password.charAt(i-1)) {
                    length++;
                    i++;
                }
                replace += length / 3;
                if (length % 3 == 0) one++;
                else if (length % 3 == 1) two++;
            } else {
                i++;
            }
        }
        
        if (n <= 20) return Math.max(missingTypes, replace);
        
        int delete = n - 20;
        replace -= Math.min(delete, one);
        replace -= Math.min(Math.max(delete - one, 0), two * 2) / 2;
        replace -= Math.max(delete - one - 2 * two, 0) / 3;
        
        return delete + Math.max(missingTypes, replace);
    }
}