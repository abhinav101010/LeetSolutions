class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = 0, bobSum = 0;
        for (int a : aliceSizes) aliceSum += a;
        for (int b : bobSizes) bobSum += b;
        
        int diff = (bobSum - aliceSum) / 2;
        
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        
        for (int a : aliceSizes) {
            int b = a + diff;
            if (bobSet.count(b)) {
                return {a, b};
            }
        }
        return {};
    }
};