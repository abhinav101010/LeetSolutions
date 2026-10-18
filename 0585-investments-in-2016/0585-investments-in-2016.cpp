#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Insurance { int pid; long tiv2015; long tiv2016; double lat; double lon; };

class Solution {
public:
    long investments2016(vector<Insurance>& insurance) {
        unordered_map<long, int> tivCount;
        unordered_map<string, int> locCount;
        for (auto& ins : insurance) {
            tivCount[ins.tiv2015]++;
            string key = to_string(ins.lat) + "|" + to_string(ins.lon);
            locCount[key]++;
        }
        long sum = 0;
        for (auto& ins : insurance) {
            if (tivCount[ins.tiv2015] > 1) {
                string key = to_string(ins.lat) + "|" + to_string(ins.lon);
                if (locCount[key] == 1) sum += ins.tiv2016;
            }
        }
        return sum;
    }
};
