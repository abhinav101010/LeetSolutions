#include <vector>
#include <string>
#include <set>
using namespace std;

struct Stadium {
    int id;
    string visit_date;
    int people;
};

class Solution {
public:
    vector<Stadium> humanTraffic(vector<Stadium>& stadium) {
        vector<Stadium> result;
        int n = stadium.size();
        vector<bool> mark(n, false);
        for (int i = 0; i <= n - 3; i++) {
            if (stadium[i].people >= 100 && 
                stadium[i+1].people >= 100 && 
                stadium[i+2].people >= 100) {
                // check if ids are consecutive in sequence
                if ((stadium[i+1].id == stadium[i].id + 1 && stadium[i+2].id == stadium[i+1].id + 1) ||
                    (stadium[i+1].id == stadium[i].id - 1 && stadium[i+2].id == stadium[i+1].id - 1) ||
                    (stadium[i].id == stadium[i+1].id + 1 && stadium[i+2].id == stadium[i].id - 1) ||
                    (stadium[i].id == stadium[i+1].id + 1 && stadium[i+2].id == stadium[i].id + 1) ||
                    (stadium[i].id == stadium[i+1].id - 1 && stadium[i+2].id == stadium[i].id - 1) ||
                    (stadium[i].id == stadium[i+1].id - 1 && stadium[i+2].id == stadium[i].id + 1)) {
                    // not quite - the SQL checks all permutations; easier to just check consecutive sequence
                }
            }
        }
        // Simpler: since data is a sequence ordered, consecutive in array means consecutive in time
        // and ids are likely consecutive
        for (int i = 0; i <= n - 3; i++) {
            if (stadium[i].people >= 100 && stadium[i+1].people >= 100 && stadium[i+2].people >= 100 &&
                stadium[i+1].id == stadium[i].id + 1 && stadium[i+2].id == stadium[i+1].id + 1) {
                mark[i] = mark[i+1] = mark[i+2] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (mark[i]) result.push_back(stadium[i]);
        }
        return result;
    }
};
