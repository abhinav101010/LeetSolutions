#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextHigher(n, 0), nextLower(n, 0);
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a,int b){ if (arr[a]!=arr[b]) return arr[a]<arr[b]; return a<b; });
        deque<int> st;
        for (int i : idx) {
            while (!st.empty() && i > st.back()) { nextHigher[st.back()] = i; st.pop_back(); }
            st.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&](int a,int b){ if (arr[a]!=arr[b]) return arr[a]>arr[b]; return a<b; });
        st.clear();
        for (int i : idx) {
            while (!st.empty() && i > st.back()) { nextLower[st.back()] = i; st.pop_back(); }
            st.push_back(i);
        }
        vector<bool> odd(n,false), even(n,false);
        odd[n-1] = even[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            odd[i] = even[nextHigher[i]];
            even[i] = odd[nextLower[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) if (odd[i]) ans++;
        return ans;
    }
};
