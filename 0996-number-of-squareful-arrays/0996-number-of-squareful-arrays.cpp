class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<char> used(n,0);
        int res=0;
        function<void(int,int)> dfs=[&](int last,int rem){
            if(rem==0){res++;return;}
            for(int i=0;i<n;i++){
                if(used[i])continue;
                if(i>0 && nums[i]==nums[i-1] && !used[i-1])continue;
                if(last!=-1){int s=last+nums[i]; int r=(int)sqrt(s); if(r*r!=s)continue;}
                used[i]=1; dfs(nums[i],rem-1); used[i]=0;
            }
        };
        dfs(-1,n);
        return res;
    }
};