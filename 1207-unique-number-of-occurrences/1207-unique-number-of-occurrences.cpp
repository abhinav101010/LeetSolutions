class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;

        for (int num : arr) {
            count[num]++;
        }

        unordered_set<int> occurrences;
        for (auto& [_, v] : count) {
            occurrences.insert(v);
        }

        return count.size() == occurrences.size();
    }
};