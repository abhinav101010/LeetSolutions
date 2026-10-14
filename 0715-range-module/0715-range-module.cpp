#include <map>
using namespace std;

class RangeModule {
private:
    map<int, int> map_;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = map_.upper_bound(left);
        if (it != map_.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second >= left) {
                left = min(left, prev_it->second);
            }
        }
        while (it != map_.end() && it->first < right) {
            right = max(right, it->second);
            it = map_.erase(it);
        }
        map_[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = map_.upper_bound(left);
        if (it == map_.begin()) return false;
        it--;
        return it->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = map_.upper_bound(left);
        if (it != map_.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second > left) {
                int val = prev_it->second;
                prev_it->second = left;
                if (val > right) {
                    map_[right] = val;
                }
            }
        }
        while (it != map_.end() && it->first < right) {
            int next = it->second;
            it = map_.erase(it);
            if (next > right) {
                map_[right] = next;
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
