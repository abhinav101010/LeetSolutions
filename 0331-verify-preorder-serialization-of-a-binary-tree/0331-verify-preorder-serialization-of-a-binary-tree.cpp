class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        string curr;
        for (char c : preorder) {
            if (c == ',') {
                nodes.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        if (!curr.empty()) nodes.push_back(curr);
        
        int slots = 1;
        for (const string& node : nodes) {
            slots--;
            if (slots < 0) return false;
            if (node != "#") {
                slots += 2;
            }
        }
        
        return slots == 0;
    }
};