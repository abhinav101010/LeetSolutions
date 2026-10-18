#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct User { int account; string name; };
struct Transaction { int transId; int account; int amount; string transactedOnDate; };

class Solution {
public:
    vector<vector<string>> bankAccountSummaryII(vector<User>& users, vector<Transaction>& transactions) {
        unordered_map<int, string> nameByAccount;
        for (auto& u : users) nameByAccount[u.account] = u.name;
        unordered_map<int, long> balance;
        for (auto& t : transactions) balance[t.account] += t.amount;
        vector<vector<string>> res;
        for (auto& u : users) {
            auto it = balance.find(u.account);
            if (it != balance.end() && it->second > 10000) {
                res.push_back({u.name, to_string(it->second)});
            }
        }
        return res;
    }
};
