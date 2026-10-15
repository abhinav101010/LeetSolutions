#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextHigher(n, 0);
        vector<int> nextLower(n, 0);
        // next higher
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] < arr[b];
            return a < b;
        });
        vector<int> stack;
        for (int i : indices) {
            while (!stack.empty() && i > stack.back()) {
                nextHigher[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        // next lower
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] > arr[b];
            return a < b;
        });
        stack.clear();
        for (int i : indices) {
            while (!stack.empty() && i > stack.back()) {
                nextLower[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        // dp
        vector<bool> odd(n, false);
        vector<bool> even(n, false);
        odd[n-1] = even[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            odd[i] = even[nextHigher[i]];
            even[i] = odd[nextLower[i]];
        }
        int ans = 0;
        for (bool b : odd) if (b) ans++;
        return ans;
    }
};
