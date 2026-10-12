class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> valToIndices;
    
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        valToIndices[val].insert(nums.size());
        nums.push_back(val);
        return valToIndices[val].size() == 1;
    }
    
    bool remove(int val) {
        if (valToIndices[val].empty()) return false;
        
        int idx = *valToIndices[val].begin();
        valToIndices[val].erase(idx);
        int last = nums.back();
        nums[idx] = last;
        valToIndices[last].insert(idx);
        valToIndices[last].erase(nums.size() - 1);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};