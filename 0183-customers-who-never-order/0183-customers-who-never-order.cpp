#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct Customer {
    int id;
    string name;
};

struct Order {
    int id;
    int customerId;
};

class Solution {
public:
    vector<string> customersWhoNeverOrder(vector<Customer>& customers, vector<Order>& orders) {
        unordered_set<int> orderedIds;
        for (const Order& o : orders) orderedIds.insert(o.customerId);
        vector<string> ans;
        for (const Customer& c : customers) {
            if (orderedIds.find(c.id) == orderedIds.end()) {
                ans.push_back(c.name);
            }
        }
        return ans;
    }
};
