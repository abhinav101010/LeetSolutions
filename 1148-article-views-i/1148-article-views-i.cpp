#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct View {
    int article_id;
    int author_id;
    int viewer_id;
    string view_date;
};

class Solution {
public:
    vector<int> articleViewsI(vector<View>& views) {
        vector<int> result;
        unordered_set<int> seen;
        for (const auto& v : views) {
            if (v.author_id == v.viewer_id) {
                seen.insert(v.author_id);
            }
        }
        result.assign(seen.begin(), seen.end());
        sort(result.begin(), result.end());
        return result;
    }
};
