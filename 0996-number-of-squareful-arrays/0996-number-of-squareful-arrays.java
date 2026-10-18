class Solution {
    public int numSquarefulPerms(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        boolean[] used=new boolean[n];
        int[] res={0};
        dfs(nums,used,-1,n,res);
        return res[0];
    }
    void dfs(int[] nums,boolean[] used,int last,int rem,int[] res){
        if(rem==0){res[0]++;return;}
        for(int i=0;i<nums.length;i++){
            if(used[i])continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1])continue;
            if(last!=-1){int s=last+nums[i]; int r=(int)Math.sqrt(s); if(r*r!=s)continue;}
            used[i]=true; dfs(nums,used,nums[i],rem-1,res); used[i]=false;
        }
    }
}