#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
    int check(vector<int>& A,vector<int>& B,int x,int n) {
        int ra=0, rb=0;
        for (int i=0;i<n;i++) {
            if (A[i]!=x && B[i]!=x) return 1000000000;
            else if (A[i]!=x) ra++;
            else if (B[i]!=x) rb++;
        }
        return min(ra,rb);
    }
public:
    int minDominoRotations(vector<int>& A,vector<int>& B) {
        int n=A.size();
        int res = min(check(A,B,A[0],n), check(A,B,B[0],n));
        return res>=1000000000?-1:res;
    }
};
