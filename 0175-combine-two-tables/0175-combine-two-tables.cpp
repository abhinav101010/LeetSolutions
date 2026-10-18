#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Person { int personId; string lastName; string firstName; };
struct Address { int addressId; int personId; string city; string state; };

class Solution {
public:
    vector<vector<string>> combineTwoTables(vector<Person>& persons, vector<Address>& addresses) {
        unordered_map<int, Address> addrMap;
        for (auto& a : addresses) addrMap[a.personId] = a;
        vector<vector<string>> res;
        for (auto& p : persons) {
            vector<string> row = {p.firstName, p.lastName};
            auto it = addrMap.find(p.personId);
            if (it != addrMap.end()) { row.push_back(it->second.city); row.push_back(it->second.state); }
            else { row.push_back(""); row.push_back(""); }
            res.push_back(row);
        }
        return res;
    }
};
