#include <vector>
#include <string>
#include <unordered_map>
#include <cstdio>
using namespace std;

struct Query {
    string query_name;
    string result;
    int position;
    int rating;
};

class Solution {
public:
    vector<vector<string>> queriesQualityAndPercentage(vector<Query>& queries) {
        unordered_map<string, vector<Query>> byName;
        for (auto& q : queries) byName[q.query_name].push_back(q);
        vector<vector<string>> ans;
        for (auto& kv : byName) {
            string name = kv.first;
            vector<Query>& qs = kv.second;
            int n = (int)qs.size();
            double quality = 0.0;
            double poor = 0.0;
            for (auto& q : qs) {
                quality += (double)q.rating / (double)q.position;
                if (q.rating < 3) poor += 1.0;
            }
            quality /= n;
            poor = poor / n * 100.0;
            char qbuf[32], pbuf[32];
            snprintf(qbuf, sizeof(qbuf), "%.2f", quality);
            snprintf(pbuf, sizeof(pbuf), "%.2f", poor);
            ans.push_back({name, qbuf, pbuf});
        }
        return ans;
    }
};
