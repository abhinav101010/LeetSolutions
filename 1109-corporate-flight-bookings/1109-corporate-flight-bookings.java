class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] diff=new int[n+2];
        for(int[]b:bookings){diff[b[0]]+=b[2]; diff[b[1]+1]-=b[2];}
        int[] res=new int[n]; int cur=0;
        for(int i=1;i<=n;i++){cur+=diff[i]; res[i-1]=cur;}
        return res;
    }
}