#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, queue<int>> pos;
        for (int i = 0; i < B.size(); i++) {
            pos[B[i]].push(i);
        }
        vector<int> res;
        for (int val : A) {
            res.push_back(pos[val].front());
            pos[val].pop();
        }
        return res;
    }
};
