class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        if (s.isEmpty()) return false;
        
        int i = 0;
        int n = s.length();
        boolean isNumeric = false;
        
        // Check sign
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            i++;
        }
        
        // Scan digits before decimal
        while (i < n && Character.isDigit(s.charAt(i))) {
            i++;
            isNumeric = true;
        }
        
        // Scan decimal point and digits after
        if (i < n && s.charAt(i) == '.') {
            i++;
            while (i < n && Character.isDigit(s.charAt(i))) {
                i++;
                isNumeric = true;
            }
        }
        
        if (!isNumeric) return false;
        
        // Scan exponent
        if (i < n && (s.charAt(i) == 'e' || s.charAt(i) == 'E')) {
            i++;
            if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
                i++;
            }
            if (i == n) return false;
            boolean expDigits = false;
            while (i < n && Character.isDigit(s.charAt(i))) {
                i++;
                expDigits = true;
            }
            if (!expDigits) return false;
        }
        
        return i == n;
    }
}