class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size();
        auto cost=[&](int start){
            vector<int> a=nums; int res=0;
            for(int i=start;i<n;i+=2){
                int need=1000;
                if(i>0) need=min(need,a[i-1]);
                if(i+1<n) need=min(need,a[i+1]);
                need--;
                if(a[i]>need){res+=a[i]-need; a[i]=need;}
            }
            return res;
        };
        return min(cost(0),cost(1));
    }}
