class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        map<int,int> cnt;
        int mx=0;
        for(int x:nums){cnt[x]++; mx=max(mx,cnt[x]);}
        return (long long)mx*k<=nums.size();
    }
};