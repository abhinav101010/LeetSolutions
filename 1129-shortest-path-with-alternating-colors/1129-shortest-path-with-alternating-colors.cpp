class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> radj(n), badj(n);
        for(auto&e:redEdges) radj[e[0]].push_back(e[1]);
        for(auto&e:blueEdges) badj[e[0]].push_back(e[1]);
        vector<int> res(n,-1); res[0]=0;
        vector<vector<char>> seen(n,vector<char>(2,0));
        seen[0][0]=seen[0][1]=1;
        deque<array<int,3>> q; q.push_back({0,0,0}); q.push_back({0,1,0});
        while(!q.empty()){
            auto [node,col,dist]=q.front(); q.pop_front();
            auto&adj = col==0?radj:badj;
            for(int nb:adj[node]){
                if(seen[nb][1-col]) continue;
                seen[nb][1-col]=1;
                if(res[nb]==-1) res[nb]=dist+1;
                q.push_back({nb,1-col,dist+1});
            }
        }
        return res;
    }