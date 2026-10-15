#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> arr = A;
        sort(arr.begin(), arr.end());
        string best = "";
        do {
            int hour = arr[0]*10 + arr[1];
            int minute = arr[2]*10 + arr[3];
            if (hour < 24 && minute < 60) {
                string t = (hour < 10 ? "0" : "") + to_string(hour) + ":" +
                           (minute < 10 ? "0" : "") + to_string(minute);
                if (t > best) {
                    best = t;
                }
            }
        } while (next_permutation(arr.begin(), arr.end()));
        return best;
    }
};
