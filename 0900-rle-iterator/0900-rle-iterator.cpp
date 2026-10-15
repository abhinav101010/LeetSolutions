#include <vector>
using namespace std;

class RLEIterator {
private:
    vector<int> encoding;
    int i; // index to frequency
    int remaining;
public:
    RLEIterator(vector<int> encoding) {
        this->encoding = encoding;
        this->i = 0;
        this->remaining = 0;
    }
    
    int next(int n) {
        while (i < encoding.size()) {
            if (remaining == 0) {
                remaining = encoding[i];
                if (remaining == 0) {
                    i += 2;
                    continue;
                }
            }
            if (remaining >= n) {
                remaining -= n;
                return encoding[i+1];
            } else {
                n -= remaining;
                remaining = 0;
                i += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_2 = obj->next(n);
 */
