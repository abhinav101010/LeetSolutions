#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();
        for (int i = 1; i <= min(10, n-1); i++) {
            if (num[0] == '0' && i > 1) break;
            long first = stol(num.substr(0, i));
            if (first > INT_MAX) break;
            for (int j = i+1; j <= min(n, i+10); j++) {
                if (num[i] == '0' && j-i > 1) break;
                long second = stol(num.substr(i, j));
                if (second > INT_MAX) break;
                vector<int> seq;
                seq.push_back((int)first);
                seq.push_back((int)second);
                int k = j;
                while (k < n) {
                    long third = (long)seq.back() + (long)seq[seq.size()-2];
                    if (third > INT_MAX) break;
                    string thirdStr = to_string(third);
                    if (num.substr(k, thirdStr.size()) == thirdStr) {
                        seq.push_back((int)third);
                        k += thirdStr.size();
                    } else {
                        break;
                    }
                }
                if (k == n && seq.size() >= 3) {
                    return seq;
                }
            }
        }
        return {};
    }
};
