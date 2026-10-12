/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        if (!result.empty() && result.back() == ',') result.pop_back();
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> vals;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            vals.push_back(token);
        }
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < (int)vals.size()) {
            TreeNode* node = q.front();
            q.pop();
            if (vals[i] != "null") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;
            if (i < (int)vals.size() && vals[i] != "null") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};