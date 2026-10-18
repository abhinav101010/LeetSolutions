class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int n=nums.length;
        java.util.function.IntUnaryOperator cost=(start)->{
            int[] a=nums.clone(); int res=0;
            for(int i=start;i<n;i+=2){
                int need=1000;
                if(i>0) need=Math.min(need,a[i-1]);
                if(i+1<n) need=Math.min(need,a[i+1]);
                need--;
                if(a[i]>need){res+=a[i]-need; a[i]=need;}
            }
            return res;
        };
        return Math.min(cost.applyAsInt(0),cost.applyAsInt(1));
    }}
