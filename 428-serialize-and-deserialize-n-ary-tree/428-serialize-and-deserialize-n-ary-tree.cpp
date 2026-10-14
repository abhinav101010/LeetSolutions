// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string res;
        serialize(root, res);
        return res;
    }
    
    void serialize(Node* node, string& res) {
        if (!node) return;
        res += to_string(node->val) + ",";
        int size = node->children.size();
        res += to_string(size) + ",";
        for (Node* child : node->children) {
            serialize(child, res);
        }
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        int pos = 0;
        return deserialize(data, pos);
    }
    
    Node* deserialize(const string& data, int& pos) {
        int comma = data.find(',', pos);
        int val = stoi(data.substr(pos, comma - pos));
        pos = comma + 1;
        comma = data.find(',', pos);
        int size = stoi(data.substr(pos, comma - pos));
        pos = comma + 1;
        Node* node = new Node(val);
        for (int i = 0; i < size; i++) {
            node->children.push_back(deserialize(data, pos));
        }
        return node;
    }
};
