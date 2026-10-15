#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, deque<int>> group;
    int maxfreq;
public:
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int x) {
        int f = freq[x] + 1;
        freq[x] = f;
        if (f > maxfreq) {
            maxfreq = f;
        }
        group[f].push_back(x);
    }
    
    int pop() {
        int x = group[maxfreq].back();
        group[maxfreq].pop_back();
        freq[x]--;
        if (group[maxfreq].empty()) {
            maxfreq--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
