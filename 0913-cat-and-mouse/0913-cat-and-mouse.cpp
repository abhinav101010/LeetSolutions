#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    static const int DRAW = 0;
    static const int MOUSE = 1;
    static const int CAT = 2;
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<string, int> memo;
        return dfs(1, 2, 0, graph, memo, n);
    }
private:
    int dfs(int mouse, int cat, int turn, const vector<vector<int>>& graph,
            unordered_map<string, int>& memo, int n) {
        string key = to_string(mouse) + "," + to_string(cat) + "," + to_string(turn);
        auto it = memo.find(key);
        if (it != memo.end()) {
            return it->second;
        }
        if (mouse == 0) {
            memo[key] = MOUSE;
            return MOUSE;
        }
        if (cat == mouse) {
            memo[key] = CAT;
            return CAT;
        }
        int res;
        if (turn == 0) { // mouse turn
            int best = CAT; // worst for mouse
            for (int next : graph[mouse]) {
                int r = dfs(next, cat, 1, graph, memo, n);
                if (r == MOUSE) {
                    memo[key] = MOUSE;
                    return MOUSE;
                }
                if (r == DRAW) {
                    best = DRAW;
                }
                // if r == CAT, best stays CAT unless we found draw
            }
            res = best;
        } else { // cat turn
            int worst = MOUSE; // best for mouse
            for (int next : graph[cat]) {
                if (next == 0) continue; // cat cannot go to hole
                int r = dfs(mouse, next, 0, graph, memo, n);
                if (r == CAT) {
                    memo[key] = CAT;
                    return CAT;
                }
                if (r == DRAW) {
                    worst = DRAW;
                }
                // if r == MOUSE, worst stays MOUSE unless draw found
            }
            res = worst;
        }
        memo[key] = res;
        return res;
    }
};
