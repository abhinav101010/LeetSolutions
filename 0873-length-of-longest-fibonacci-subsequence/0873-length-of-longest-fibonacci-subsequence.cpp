#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int n = arr.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                long a = arr[i];
                long b = arr[j];
                int length = 2;
                while (s.find(a + b) != s.end()) {
                    long sum = a + b;
                    a = b;
                    b = sum;
                    length++;
                }
                if (length > best) {
                    best = length;
                }
            }
        }
        return best >= 3 ? best : 0;
    }
};
