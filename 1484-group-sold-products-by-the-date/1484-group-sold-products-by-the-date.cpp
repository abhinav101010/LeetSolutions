#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Activities {
    string sell_date;
    string product;
};

struct Result {
    string sell_date;
    int num_sold;
    string products;
};

class Solution {
public:
    vector<Result> groupSoldProducts(vector<Activities>& activities) {
        vector<Result> results;
        // Group by sell_date: map from date to set of products (or sorted set)
        map<string, set<string>> dateToProducts;
        for (const auto& a : activities) {
            dateToProducts[a.sell_date].insert(a.product);
        }
        for (const auto& [date, prodSet] : dateToProducts) {
            Result r;
            r.sell_date = date;
            r.num_sold = prodSet.size();
            // build comma-separated products in lexicographic order (set is already sorted)
            string prodStr;
            for (auto it = prodSet.begin(); it != prodSet.end(); ++it) {
                if (it != prodSet.begin()) prodStr += ",";
                prodStr += *it;
            }
            r.products = prodStr;
            results.push_back(r);
        }
        return results;
    }
};
