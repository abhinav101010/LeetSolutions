#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Patient {
    int patient_id;
    string patient_name;
    string conditions;
};

class Solution {
public:
    vector<vector<string>> patientsWithCondition(vector<Patient>& patients) {
        vector<vector<string>> ans;
        for (auto& p : patients) {
            bool match = false;
            if (p.conditions.size() >= 5 && p.conditions.compare(0, 5, "DIAB1") == 0) match = true;
            if (!match && p.conditions.find(" DIAB1") != string::npos) match = true;
            if (match) ans.push_back({to_string(p.patient_id), p.patient_name, p.conditions});
        }
        return ans;
    }
};
