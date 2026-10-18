#include <vector>
#include <string>
#include <map>
using namespace std;

struct Orders {
    int order_number;
    int customer_number;
};

class Solution {
public:
    vector<vector<string>> largestOrders(const vector<Orders>& orders) {
        map<int, int> cnt;
        for (const auto& o : orders) cnt[o.customer_number]++;
        int bestCust = -1, bestCnt = -1;
        for (const auto& kv : cnt) {
            if (kv.second > bestCnt) {
                bestCnt = kv.second;
                bestCust = kv.first;
            }
        }
        vector<vector<string>> result;
        if (bestCust != -1) result.push_back({to_string(bestCust)});
        return result;
    }
};
