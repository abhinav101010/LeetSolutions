#include <vector>
#include <string>
#include <set>
#include <map>
#include <optional>
#include <algorithm>
using namespace std;

struct Tree {
    int id;
    optional<int> p_id;
};

class Solution {
public:
    vector<vector<string>> treeNode(const vector<Tree>& tree) {
        set<int> isParent;
        for (const auto& t : tree)
            if (t.p_id.has_value()) isParent.insert(*t.p_id);
        vector<Tree> nodes = tree;
        sort(nodes.begin(), nodes.end(), [](const Tree& a, const Tree& b) {
            return a.id < b.id;
        });
        vector<vector<string>> result;
        for (const auto& t : nodes) {
            string type;
            if (!t.p_id.has_value()) type = "Root";
            else if (isParent.count(t.id)) type = "Inner";
            else type = "Leaf";
            result.push_back({to_string(t.id), type});
        }
        return result;
    }
};
