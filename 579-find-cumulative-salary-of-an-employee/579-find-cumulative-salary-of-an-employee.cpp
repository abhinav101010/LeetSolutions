#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct Emp { int id; int month; int salary; };
class Solution {
public:
    vector<vector<int>> cumulativeSalary(vector<Emp> e) {
        map<int,map<int,int>> byid;
        for (auto &x : e) byid[x.id][x.month]=x.salary;
        vector<vector<int>> r;
        for (auto &[id, months] : byid) {
            vector<int> ms;
            for (auto &kv : months) ms.push_back(kv.first);
            sort(ms.begin(),ms.end());
            int maxm = ms.back();
            for (int m : ms) {
                if (m == maxm) continue; // exclude latest month per SQL? Actually SQL includes all but subtracts latest's salary contribution? 
                int sum=0;
                // sum over preceding 2 months including current
                for (int mm : ms) if (mm<=m && mm>=m-2) sum+=months[mm];
                r.push_back({id,m,sum});
            }
        }
        return r;
    }
};
