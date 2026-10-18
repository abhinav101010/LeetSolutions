#include <vector>
#include <string>
#include <optional>
using namespace std;

struct Customer {
    int id;
    string name;
    optional<int> referee_id;
};

class Solution {
public:
    vector<string> findCustomerReferee(vector<Customer>& customers) {
        vector<string> ans;
        for (const Customer& c : customers) {
            if (!c.referee_id.has_value() || c.referee_id.value() != 2) {
                ans.push_back(c.name);
            }
        }
        return ans;
    }
};
