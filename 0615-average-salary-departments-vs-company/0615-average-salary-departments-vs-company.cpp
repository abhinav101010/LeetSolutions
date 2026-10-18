#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
struct Emp { int id; int salary; int managerId; string company; };
class Solution {
public:
    vector<string> companiesBelowAvg(vector<Emp> e) {
        // company where dept avg < company avg of managers
        map<string,vector<int>> allsal;
        for (auto &x : e) allsal[x.company].push_back(x.salary);
        vector<string> r;
        // managers per company
        for (auto &kv : allsal) {
            string comp = kv.first;
            // managers in company
            set<int> mgrs;
            for (auto &x : e) if (x.company==comp && x.managerId!=0) mgrs.insert(x.managerId);
            // avg of managers' salaries
            double ms=0, mc=0;
            for (auto &x : e) if (x.company==comp && mgrs.count(x.id)) { ms+=x.salary; mc++; }
            double compavg=0; for(int s:kv.second) compavg+=s; compavg/=kv.second.size();
            if (mc>0 && compavg < ms/mc) r.push_back(comp);
        }
        return r;
    }
};
