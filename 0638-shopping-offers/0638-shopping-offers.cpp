class Solution {
private:
    int n;
    vector<int> price;
    vector<vector<int>> special;
    unordered_map<string, int> memo;
    
    string key(const vector<int>& arr) {
        string s;
        for (int v : arr) s += to_string(v) + ",";
        return s;
    }
    
    int dfs(vector<int>& needs) {
        string k = key(needs);
        if (memo.count(k)) return memo[k];
        
        int res = 0;
        for (int i = 0; i < n; i++) res += price[i] * needs[i];
        
        for (const auto& offer : special) {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (needs[i] < offer[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                vector<int> newNeeds = needs;
                for (int i = 0; i < n; i++) newNeeds[i] -= offer[i];
                res = min(res, offer[n] + dfs(newNeeds));
            }
        }
        
        memo[k] = res;
        return res;
    }

public:
    int shoppingOffers(vector<int>& priceList, vector<vector<int>>& specialList, vector<int>& needsList) {
        n = priceList.size();
        price = priceList;
        special = specialList;
        return dfs(needsList);
    }
};