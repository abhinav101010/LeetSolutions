#include <vector>
#include <string>
#include <map>
using namespace std;

struct Product {
    int product_id;
    string product_name;
    string product_category;
};

struct Order {
    int product_id;
    string order_date;
    int unit;
};

class Solution {
public:
    vector<vector<string>> productsOrdered(const vector<Product>& products, const vector<Order>& orders) {
        map<int, string> pname;
        for (const auto& p : products) pname[p.product_id] = p.product_name;
        map<int, int> units;
        for (const auto& o : orders) {
            if (o.order_date >= "2020-02-01" && o.order_date < "2020-03-01")
                units[o.product_id] += o.unit;
        }
        vector<vector<string>> result;
        for (const auto& kv : units) {
            if (kv.second >= 100 && pname.count(kv.first))
                result.push_back({pname[kv.first], to_string(kv.second)});
        }
        return result;
    }
};
