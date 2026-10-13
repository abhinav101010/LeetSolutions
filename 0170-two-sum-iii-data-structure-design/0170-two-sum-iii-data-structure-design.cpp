#include <unordered_map>
using namespace std;

class TwoSum {
public:
    unordered_map<int, int> count;
    TwoSum() {}
    void add(int number) {
        count[number]++;
    }
    bool find(int value) {
        for (auto& p : count) {
            int num = p.first;
            int complement = value - num;
            if (count.find(complement) != count.end()) {
                if (complement != num || count[num] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};