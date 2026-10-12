class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        string sign = "";
        if (num < 0) {
            sign = "-";
            num = -num;
        }
        
        string ans;
        while (num > 0) {
            int remainder = num % 7;
            ans = to_string(remainder) + ans;
            num /= 7;
        }
        
        return sign + ans;
    }
};