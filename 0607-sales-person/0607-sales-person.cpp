#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct SalesPerson { int salesId; string name; int salary; int commissionRate; string hireDate; };
struct Company { int comId; string name; string city; };
struct Order { int orderId; string date; int comId; int salesId; int amount; };

class Solution {
public:
    vector<string> salesPerson(vector<SalesPerson>& salesPersons, vector<Company>& companies, vector<Order>& orders) {
        unordered_set<int> redComIds;
        for (auto& c : companies) if (c.name == "RED") redComIds.insert(c.comId);
        unordered_set<int> badSalesIds;
        for (auto& o : orders) if (redComIds.count(o.comId)) badSalesIds.insert(o.salesId);
        vector<string> res;
        for (auto& s : salesPersons) if (!badSalesIds.count(s.salesId)) res.push_back(s.name);
        return res;
    }
};
