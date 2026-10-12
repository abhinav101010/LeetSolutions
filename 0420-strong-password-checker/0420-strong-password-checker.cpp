class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int missingLower = 1, missingUpper = 1, missingDigit = 1;
        
        for (char c : password) {
            if (islower(c)) missingLower = 0;
            else if (isupper(c)) missingUpper = 0;
            else if (isdigit(c)) missingDigit = 0;
        }
        
        int missingTypes = missingLower + missingUpper + missingDigit;
        
        if (n < 6) return max(6 - n, missingTypes);
        
        int replace = 0, one = 0, two = 0;
        int i = 2;
        while (i < n) {
            if (password[i] == password[i-1] && password[i] == password[i-2]) {
                int length = 2;
                while (i < n && password[i] == password[i-1]) {
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
        
        if (n <= 20) return max(missingTypes, replace);
        
        int delete = n - 20;
        replace -= min(delete, one);
        replace -= min(max(delete - one, 0), two * 2) / 2;
        replace -= max(delete - one - 2 * two, 0) / 3;
        
        return delete + max(missingTypes, replace);
    }
};