class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int cur=0,best=0; unordered_map<int,int> seen{{0,-1}};
        for(int i=0;i<hours.size();i++){
            cur += hours[i]>8?1:-1;
            if(cur>0) best=i+1;
            else if(seen.count(cur-1)) best=max(best,i-seen[cur-1]);
            if(!seen.count(cur)) seen[cur]=i;
        }
        return best;
    }