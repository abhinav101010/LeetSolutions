class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!map.count(key)) return -1;
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            cache.erase(map[key]);
        } else if ((int)cache.size() == capacity) {
            int lruKey = cache.back().first;
            map.erase(lruKey);
            cache.pop_back();
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};