#include <vector>
#include <algorithm>
using namespace std;

struct Number {
    int num;
    int frequency;
};

class Solution {
public:
    double findMedian(vector<Number>& numbers) {
        if (numbers.empty()) return 0.0;
        vector<Number> ns = numbers;
        sort(ns.begin(), ns.end(), [](const Number& a, const Number& b) {
            return a.num < b.num;
        });
        long long total = 0;
        for (const Number& n : ns) total += n.frequency;
        long long low = (total + 1) / 2;
        long long high = (total + 2) / 2;
        long long cum = 0;
        vector<int> medians;
        for (const Number& n : ns) {
            long long start = cum + 1;
            cum += n.frequency;
            long long end = cum;
            long long s = max(start, low);
            long long e = min(end, high);
            for (long long pos = s; pos <= e; pos++) {
                medians.push_back(n.num);
            }
        }
        if (medians.empty()) return 0.0;
        double sum = 0.0;
        for (int x : medians) sum += (double)x;
        return sum / (double)medians.size();
    }
};
