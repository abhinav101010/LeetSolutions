#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string& w : words) {
            freq[w]++;
        }
        vector<string> list;
        for (auto& p : freq) {
            list.push_back(p.first);
        }
        sort(list.begin(), list.end(), [&](const string& a, const string& b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b]; // descending frequency
            }
            return a < b; // ascending lexicographically
        });
        return vector<string>(list.begin(), list.begin() + k);
    }
};
