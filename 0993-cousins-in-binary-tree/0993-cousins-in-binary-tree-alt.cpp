#include <queue>
using namespace std;
struct TreeNode {
    int val; TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*l,TreeNode*r):val(x),left(l),right(r){}
};
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<tuple<TreeNode*,int,int>> q;
        q.push(make_tuple(root,0,0));
        int px=-1,py=-1,dx=-1,dy=-1;
        while (!q.empty()) {
            auto [node,depth,pv] = q.front(); q.pop();
            if (node->val == x) { px=pv; dx=depth; }
            if (node->val == y) { py=pv; dy=depth; }
            if (px!=-1 && py!=-1) break;
            if (node->left) q.push(make_tuple(node->left,depth+1,node->val));
            if (node->right) q.push(make_tuple(node->right,depth+1,node->val));
        }
        return dx==dy && px!=py;
    }
};
