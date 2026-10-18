#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

struct Price {
    int product_id;
    string start_date;
    string end_date;
    int price;
};

struct Unit {
    int product_id;
    string purchase_date;
    int units;
};

struct Result {
    int product_id;
    double average_price;
};

class Solution {
public:
    vector<Result> averageSellingPrice(vector<Price>& prices, vector<Unit>& units) {
        map<int, double> avg;
        for (const Price& p : prices) avg[p.product_id] = 0.0;

        map<int, vector<Unit>> byProd;
        for (const Unit& u : units) byProd[u.product_id].push_back(u);

        for (auto& kv : byProd) {
            int pid = kv.first;
            if (avg.find(pid) == avg.end()) avg[pid] = 0.0;
            double sumPu = 0.0;
            double sumU = 0.0;
            for (const Unit& u : kv.second) {
                for (const Price& p : prices) {
                    if (p.product_id == pid && u.purchase_date >= p.start_date && u.purchase_date <= p.end_date) {
                        sumPu += (double)p.price * (double)u.units;
                        sumU += (double)u.units;
                        break;
                    }
                }
            }
            if (sumU > 0.0) {
                avg[pid] = round(sumPu / sumU * 100.0) / 100.0;
            } else {
                avg[pid] = 0.0;
            }
        }

        vector<Result> ans;
        for (const auto& kv : avg) {
            ans.push_back({kv.first, kv.second});
        }
        return ans;
    }
};
