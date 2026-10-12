class Solution {
public:
    bool isNumber(string s) {
        // Trim leading and trailing spaces
        int start = 0;
        while (start < (int)s.size() && s[start] == ' ') start++;
        int end = s.size() - 1;
        while (end >= start && s[end] == ' ') end--;
        if (start > end) return false;
        
        int i = start;
        bool isNumeric = false;
        
        // Check sign
        if (s[i] == '+' || s[i] == '-') i++;
        
        // Scan digits before decimal
        while (i <= end && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }
        
        // Scan decimal point and digits after
        if (i <= end && s[i] == '.') {
            i++;
            while (i <= end && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }
        
        if (!isNumeric) return false;
        
        // Scan exponent
        if (i <= end && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i <= end && (s[i] == '+' || s[i] == '-')) i++;
            if (i > end) return false;
            bool expDigits = false;
            while (i <= end && isdigit(s[i])) {
                i++;
                expDigits = true;
            }
            if (!expDigits) return false;
        }
        
        return i == end + 1;
    }
};