#include <vector>
#include <string>
using namespace std;

struct Product {
    int product_id;
    string low_fats;
    string recyclable;
};

class Solution {
public:
    vector<vector<string>> recyclableProducts(const vector<Product>& products) {
        vector<vector<string>> result;
        for (const auto& p : products)
            if (p.low_fats == "Y" && p.recyclable == "Y")
                result.push_back({to_string(p.product_id)});
        return result;
    }
};
