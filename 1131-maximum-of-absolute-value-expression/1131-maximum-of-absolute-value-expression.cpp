class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(), best=0;
        for(int s1:{-1,1}) for(int s2:{-1,1}) for(int s3:{-1,1}){
            int mx=INT_MIN, mn=INT_MAX;
            for(int i=0;i<n;i++){int v=s1*arr1[i]+s2*arr2[i]+s3*i; mx=max(mx,v); mn=min(mn,v);}
            best=max(best,mx-mn);
        }
        return best;
    }}
