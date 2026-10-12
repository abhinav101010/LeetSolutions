class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;
        bool negFirst = true;
        bool started = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ' && !started) continue; 
            if(s[i] == '+' && !started && i+1 < s.length() && isdigit(s[i+1])) continue;
            if(s[i] == '-' && !started && i+1 < s.length() && s[i+1] == '+') return 0;
            else if(s[i] == '+' && !started && i+1 < s.length() && s[i+1] == '-') return 0;
            if(s[i] == '-' && negFirst){ sign = -1; negFirst = false; continue; }
            if(!isdigit(s[i])) break;
            else {
                if(result > INT_MAX/10 || (result == INT_MAX/10 && (s[i]-'0') > 7))
                    return sign == 1 ? INT_MAX : INT_MIN;
                result = result * 10 + (s[i] - '0');
                negFirst = false;
                started = true;
            }
        }
        return result * sign;
    }
};