class Solution {
public:
    int numberOfDays(int Y, int M) {
        switch (M) {
            case 2: {
                bool leap = (Y%4==0 && Y%100!=0) || (Y%400==0);
                return leap ? 29 : 28;
            }
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }
};
