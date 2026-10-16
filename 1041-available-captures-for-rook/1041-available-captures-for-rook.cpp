#include <vector>
using namespace std;
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r=0,c=0;
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                if (board[i][j]=='R') { r=i; c=j; break; }
            }
        }
        int ans = 0;
        vector<vector<int>> dirs {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto &d:dirs) {
            int nr=r+d[0], nc=c+d[1];
            while (nr>=0&&nr<8&&nc>=0&&nc<8) {
                if (board[nr][nc]=='B') break;
                if (board[nr][nc]=='p') { ans++; break; }
                nr+=d[0]; nc+=d[1];
            }
        }
        return ans;
    }
};
