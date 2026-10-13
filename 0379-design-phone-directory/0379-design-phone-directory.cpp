class PhoneDirectory {
public:
    unordered_set<int> available;
    int maxNumbers;
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        for (int i = 0; i < maxNumbers; i++) {
            available.insert(i);
        }
    }
    int get() {
        if (available.empty()) return -1;
        int num = *available.begin();
        available.erase(num);
        return num;
    }
    bool check(int number) {
        return available.find(number) != available.end();
    }
    void release(int number) {
        if (number >= 0 && number < maxNumbers) {
            available.insert(number);
        }
    }
};