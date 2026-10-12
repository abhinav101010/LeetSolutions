class Solution {
public:
    inline int getNumber(char c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        if(c == 'M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int prevn = 0, number = 0;
        for(char c : s){
            int n = getNumber(c);
            if(prevn < n && prevn){
                number -= 2*prevn;
            }
            number += n;
            prevn = n;
        }

        cout << number;
        return number;
    }
};