/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
private:
    void dfs(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (!node) return;
        if (graph.find(node) == graph.end()) {
            graph[node] = vector<TreeNode*>();
        }
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        dfs(node->left, node, graph);
        dfs(node->right, node, graph);
    }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        dfs(root, nullptr, graph);
        TreeNode* target = nullptr;
        for (auto& kv : graph) {
            if (kv.first->val == k) {
                target = kv.first;
                break;
            }
        }
        if (!target) return -1; // should not happen
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            // leaf in original tree: no left and right child
            if (!node->left && !node->right) {
                return node->val;
            }
            for (TreeNode* nei : graph[node]) {
                if (visited.find(nei) == visited.end()) {
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }
        return -1; // should not happen
    }
};
