class Solution {
public:
    bool isArmstrong(int n) {
        string s=to_string(n); int p=s.size();
        long long sum=0; for(char c:s) sum+=pow(c-'0',p);
        return sum==n;
    }}
