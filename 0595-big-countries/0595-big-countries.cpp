#include <vector>
#include <string>
using namespace std;
struct World { string name; int population; int area; };
class Solution {
public:
    vector<vector<string>> bigCountries(vector<World> w) {
        vector<vector<string>> r;
        for (auto &x : w) if (x.area >= 3000000 || x.population >= 25000000)
            r.push_back({x.name, to_string(x.population), to_string(x.area)});
        return r;
    }
};
