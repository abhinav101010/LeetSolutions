#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TopVotedAce {
private:
    vector<int> times;
    vector<int> leaders;
public:
    TopVotedAce(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int,int> count;
        int leader = -1;
        int maxvotes = 0;
        leaders.resize(times.size());
        for (int i = 0; i < persons.size(); i++) {
            int p = persons[i];
            count[p] = count.count(p) ? count[p] + 1 : 1;
            if (count[p] >= maxvotes) {
                maxvotes = count[p];
                leader = p;
            }
            leaders[i] = leader;
        }
    }
    int q(int t) {
        auto it = upper_bound(times.begin(), times.end(), t);
        int idx = distance(times.begin(), it) - 1;
        return leaders[idx];
    }
};

/**
 * Your TopVotedAce object will be instantiated and called as such:
 * TopVotedAce* obj = new TopVotedAce(persons, times);
 * int param_1 = obj->q(t);
 */
