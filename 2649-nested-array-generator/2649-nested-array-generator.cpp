// 2649-nested-array-generator
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(const vector<any> &arr, vector<int> &res) {
        for (auto &x : arr) {
            if (x.type() == typeid(int)) {
                res.push_back(any_cast<int>(x));
            } else {
                dfs(any_cast<vector<any>>(x), res);
            }
        }
    }
    
    vector<int> inorderTraversal(const vector<any> &arr) {
        vector<int> res;
        dfs(arr, res);
        return res;
    }
};
