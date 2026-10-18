#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
struct Product { int product_id; string product_name; };
struct Sale { int product_id; string sale_date; };
class Solution {
public:
    vector<vector<string>> salesAnalysis(vector<Product> products, vector<Sale> sales) {
        map<int, pair<string,string>> agg; // min,max
        map<int,string> name;
        for (auto &p : products) name[p.product_id]=p.product_name;
        for (auto &s : sales) {
            if (!agg.count(s.product_id)) agg[s.product_id]={s.sale_date,s.sale_date};
            else {
                agg[s.product_id].first=min(agg[s.product_id].first,s.sale_date);
                agg[s.product_id].second=max(agg[s.product_id].second,s.sale_date);
            }
        }
        vector<vector<string>> r;
        for (auto &[pid,mm] : agg) {
            if (mm.first >= "2019-01-01" && mm.second <= "2019-03-31")
                r.push_back({to_string(pid), name[pid]});
        }
        return r;
    }
};
