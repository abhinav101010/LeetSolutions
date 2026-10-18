class Solution {
    public int numberOfDays(int Y, int M) {
        if(M==2) return (Y%4==0&&(Y%100!=0||Y%400==0))?29:28;
        if(M==4||M==6||M==9||M==11) return 30;
        return 31;
    }
}