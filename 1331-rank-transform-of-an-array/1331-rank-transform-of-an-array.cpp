#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sorted) {
            if (!rankMap.count(num)) {
                rankMap[num] = rank++;
            }
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = rankMap[arr[i]];
        }
        return result;
    }
};