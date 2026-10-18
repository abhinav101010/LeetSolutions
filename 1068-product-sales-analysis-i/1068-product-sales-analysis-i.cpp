#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Product { int productId; string productName; };
struct Sale { int saleId; int productId; int year; int quantity; int price; };

class Solution {
public:
    vector<vector<string>> productSalesAnalysisI(vector<Product>& products, vector<Sale>& sales) {
        unordered_map<int, string> pname;
        for (auto& p : products) pname[p.productId] = p.productName;
        vector<vector<string>> res;
        for (auto& s : sales) {
            auto it = pname.find(s.productId);
            if (it != pname.end()) {
                res.push_back({it->second, to_string(s.year), to_string(s.price)});
            }
        }
        return res;
    }
};
