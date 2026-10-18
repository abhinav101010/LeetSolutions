// 2619-array-prototype-last
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int last(vector<int>& arr) {
        if (arr.empty()) return -1; // or handle as appropriate
        return arr.back();
    }
};
