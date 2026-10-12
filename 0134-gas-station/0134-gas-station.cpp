class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) return -1;
        
        int total = 0;
        int start = 0;
        
        for (int i = 0; i < (int)gas.size(); i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        
        return start < (int)gas.size() ? start : -1;
    }
};