#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

struct Visit {
    int visit_id;
    int customer_id;
};

struct Transaction {
    int transaction_id;
    int visit_id;
    int amount;
};

struct Result {
    int customer_id;
    int count_no_trans;
};

class Solution {
public:
    vector<Result> customerVisitsWithoutTransactions(vector<Visit>& visits, vector<Transaction>& transactions) {
        unordered_set<int> withTrans;
        for (const Transaction& t : transactions) withTrans.insert(t.visit_id);
        map<int, int> cnt;
        for (const Visit& v : visits) {
            if (withTrans.find(v.visit_id) == withTrans.end()) {
                cnt[v.customer_id]++;
            }
        }
        vector<Result> ans;
        for (const auto& kv : cnt) {
            ans.push_back({kv.first, kv.second});
        }
        return ans;
    }
};
