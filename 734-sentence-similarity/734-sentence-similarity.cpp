#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_set<string> similar;
        for (auto& p : pairs) {
            similar.insert(p[0] + "#" + p[1]);
            similar.insert(p[1] + "#" + p[0]);
        }
        for (size_t i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) continue;
            if (similar.find(words1[i] + "#" + words2[i]) == similar.end()) {
                return false;
            }
        }
        return true;
    }
};
