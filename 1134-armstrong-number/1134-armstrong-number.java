class Solution {
    public boolean isArmstrong(int n) {
        String s=String.valueOf(n); int p=s.length();
        long sum=0; for(char c:s) sum+=(long)Math.pow(c-'0',p);
        return sum==n;
    }}
