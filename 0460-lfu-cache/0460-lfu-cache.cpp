class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (!keyToVal.count(key)) return -1;
        updateFreq(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyToVal.count(key)) {
            keyToVal[key] = value;
            updateFreq(key);
            return;
        }
        
        if (keyToVal.size() >= capacity) {
            int evictKey = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            keyToVal.erase(evictKey);
            keyToFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }
        
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_back(key);
        keyToIter[key] = prev(freqToKeys[1].end());
        minFreq = 1;
    }

private:
    void updateFreq(int key) {
        int freq = keyToFreq[key];
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        
        int newFreq = freq + 1;
        keyToFreq[key] = newFreq;
        freqToKeys[newFreq].push_back(key);
        keyToIter[key] = prev(freqToKeys[newFreq].end());
    }
};