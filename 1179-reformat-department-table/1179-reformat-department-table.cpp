#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

struct Department {
    int id;
    int revenue;
    string month;
};

class Solution {
public:
    vector<vector<string>> reformatTable(vector<Department>& department) {
        unordered_map<int, vector<pair<string, int>>> map;
        // collect
        for (auto& d : department) {
            map[d.id].push_back({d.month, d.revenue});
        }
        vector<vector<string>> res;
        // get months in order
        const vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (auto& [id, items] : map) {
            vector<string> row;
            row.push_back(to_string(id));
            // build map for this id
            unordered_map<string, int> rev;
            for (auto& it : items) rev[it.first] = it.second;
            for (auto& m : months) {
                if (rev.find(m) != rev.end()) {
                    row.push_back(to_string(rev[m]));
                } else {
                    row.push_back("null");
                }
            }
            res.push_back(row);
        }
        // sort by id
        sort(res.begin(), res.end(), [](auto& a, auto& b) {
            return stoi(a[0]) < stoi(b[0]);
        });
        return res;
    }
};
