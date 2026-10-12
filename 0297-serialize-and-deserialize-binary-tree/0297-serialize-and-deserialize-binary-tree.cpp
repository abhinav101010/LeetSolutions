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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }
    
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "N,";
            return;
        }
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        string curr;
        for (char c : data) {
            if (c == ',') {
                vals.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        index = 0;
        return deserializeHelper(vals);
    }
    
private:
    int index;
    
    TreeNode* deserializeHelper(vector<string>& vals) {
        if (vals[index] == "N") {
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vals[index]));
        index++;
        node->left = deserializeHelper(vals);
        node->right = deserializeHelper(vals);
        return node;
    }
};