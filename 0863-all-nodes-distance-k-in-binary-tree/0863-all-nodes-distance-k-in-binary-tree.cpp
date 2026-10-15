// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* par) {
            if (node) {
                parent[node] = par;
                dfs(node->left, node);
                dfs(node->right, node);
            }
        };
        dfs(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dist = 0;
        while (!q.empty() && dist < k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                TreeNode* par = parent[node];
                if (par && visited.find(par) == visited.end()) {
                    visited.insert(par);
                    q.push(par);
                }
            }
            dist++;
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
