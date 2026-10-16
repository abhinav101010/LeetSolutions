#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val; TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*l,TreeNode*r):val(x),left(l),right(r){}
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> res;
        queue<tuple<TreeNode*,int,int>> q;
        q.push(make_tuple(root,0,0));
        while (!q.empty()) {
            auto [node,col,row] = q.front(); q.pop();
            res[col][row].push_back(node->val);
            if (node->left) q.push(make_tuple(node->left,col-1,row+1));
            if (node->right) q.push(make_tuple(node->right,col+1,row+1));
        }
        vector<vector<int>> ans;
        for (auto &pcol : res) {
            vector<int> colList;
            for (auto &prow : pcol.second) {
                sort(prow.second.begin(), prow.second.end());
                colList.insert(colList.end(), prow.second.begin(), prow.second.end());
            }
            ans.push_back(colList);
        }
        return ans;
    }
};
