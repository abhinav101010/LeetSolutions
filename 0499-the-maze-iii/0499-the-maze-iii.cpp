#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    struct Node {
        int x, y;
        int dist;
        string path;
        Node(int x, int y, int dist, string path) : x(x), y(y), dist(dist), path(path) {}
    };
    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            if (a.dist != b.dist) return a.dist > b.dist;
            return a.path > b.path;
        }
    };

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<char> dirChar = {'u','d','l','r'};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<string>> path(m, vector<string>(n, ""));
        priority_queue<Node, vector<Node>, CompareNode> pq;
        int sx = ball[0], sy = ball[1];
        dist[sx][sy] = 0;
        path[sx][sy] = "";
        pq.push(Node(sx, sy, 0, ""));
        while (!pq.empty()) {
            Node cur = pq.top(); pq.pop();
            int x = cur.x, y = cur.y;
            int d = cur.dist;
            string p = cur.path;
            if (d > dist[x][y] || (d == dist[x][y] && p > path[x][y])) {
                continue;
            }
            if (x == hole[0] && y == hole[1]) {
                return p;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x, ny = y;
                int steps = 0;
                while (nx + dirs[i][0] >= 0 && nx + dirs[i][0] < m &&
                       ny + dirs[i][1] >= 0 && ny + dirs[i][1] < n &&
                       maze[nx + dirs[i][0]][ny + dirs[i][1]] == 0) {
                    nx += dirs[i][0];
                    ny += dirs[i][1];
                    steps++;
                    if (nx == hole[0] && ny == hole[1]) {
                        break;
                    }
                }
                int nd = d + steps;
                string np = p + dirChar[i];
                if (nd < dist[nx][ny] || (nd == dist[nx][ny] && np < path[nx][ny])) {
                    dist[nx][ny] = nd;
                    path[nx][ny] = np;
                    pq.push(Node(nx, ny, nd, np));
                }
            }
        }
        return "impossible";
    }
};
