#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> sortedA = A;
        sort(sortedA.begin(), sortedA.end());
        vector<pair<int,int>> sortedB;
        for (int i = 0; i < n; i++) {
            sortedB.push_back({B[i], i});
        }
        sort(sortedB.begin(), sortedB.end());
        vector<int> res(n);
        int left = 0, right = n-1;
        for (int k = n-1; k >= 0; k--) {
            int b = sortedB[k].first;
            int idx = sortedB[k].second;
            if (sortedA[right] > b) {
                res[idx] = sortedA[right];
                right--;
            } else {
                res[idx] = sortedA[left];
                left++;
            }
        }
        return res;
    }
};
