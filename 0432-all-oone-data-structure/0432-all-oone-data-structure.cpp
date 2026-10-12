class AllOne {
private:
    unordered_map<string, int> keyCount;
    unordered_map<int, unordered_set<string>> countKeys;
    int minCount = 0;
    int maxCount = 0;
    
public:
    AllOne() {}
    
    void inc(string key) {
        int oldCount = keyCount[key];
        int newCount = oldCount + 1;
        keyCount[key] = newCount;
        
        if (oldCount > 0) {
            countKeys[oldCount].erase(key);
            if (countKeys[oldCount].empty()) {
                countKeys.erase(oldCount);
                if (minCount == oldCount) {
                    minCount = countKeys.empty() ? 0 : INT_MAX;
                    for (auto& [k, v] : countKeys) minCount = min(minCount, k);
                }
            }
        }
        
        countKeys[newCount].insert(key);
        maxCount = max(maxCount, newCount);
        if (minCount == 0 || newCount < minCount) minCount = newCount;
    }
    
    void dec(string key) {
        if (!keyCount.count(key)) return;
        
        int oldCount = keyCount[key];
        int newCount = oldCount - 1;
        
        countKeys[oldCount].erase(key);
        if (countKeys[oldCount].empty()) {
            countKeys.erase(oldCount);
            if (maxCount == oldCount) {
                maxCount = countKeys.empty() ? 0 : 0;
                for (auto& [k, v] : countKeys) maxCount = max(maxCount, k);
            }
        }
        
        if (newCount == 0) {
            keyCount.erase(key);
            if (countKeys.empty()) minCount = 0;
            else {
                minCount = INT_MAX;
                for (auto& [k, v] : countKeys) minCount = min(minCount, k);
            }
        } else {
            keyCount[key] = newCount;
            countKeys[newCount].insert(key);
            if (minCount == 0 || newCount < minCount) minCount = newCount;
        }
    }
    
    string getMaxKey() {
        if (countKeys.empty()) return "";
        return *countKeys[maxCount].begin();
    }
    
    string getMinKey() {
        if (countKeys.empty()) return "";
        return *countKeys[minCount].begin();
    }
};