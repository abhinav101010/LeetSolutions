class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int k) {
        Map<Integer,Integer> cnt=new HashMap<>();
        int mx=0;
        for(int x:nums){cnt.put(x,cnt.getOrDefault(x,0)+1); mx=Math.max(mx,cnt.get(x));}
        return (long)mx*k<=nums.length;
    }
}