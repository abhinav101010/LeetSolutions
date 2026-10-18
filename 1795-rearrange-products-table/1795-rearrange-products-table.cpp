#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>

using namespace std;

struct Product {
    int product_id;
    int store1;
    int store2;
    int store3;
    // use -1 to represent null
};

class Solution {
public:
    vector<tuple<int, string, int> > rearrange(vector<Product> &products) {
        vector<tuple<int, string, int> > res;
        for (const auto &p : products) {
            if (p.store1 != -1) { // treat -1 as null
                res.push_back(make_tuple(p.product_id, "store1", p.store1));
            }
            if (p.store2 != -1) {
                res.push_back(make_tuple(p.product_id, "store2", p.store2));
            }
            if (p.store3 != -1) {
                res.push_back(make_tuple(p.product_id, "store3", p.store3));
            }
        }
        return res;
    }
};
