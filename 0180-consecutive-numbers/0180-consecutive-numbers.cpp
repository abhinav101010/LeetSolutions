#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cstddef>
using namespace std;

struct Log {
    int id;
    string num;
};

class Solution {
public:
    vector<string> consecutiveNumbers(vector<Log>& logs) {
        vector<string> result;
        if (logs.size() < 3) {
            return result;
        }
        // Sort logs by id to ensure consecutive
        vector<Log> sortedLogs = logs;
        sort(sortedLogs.begin(), sortedLogs.end(), [](const Log& a, const Log& b) {
            return a.id < b.id;
        });
        
        for (size_t i = 0; i <= sortedLogs.size() - 3; ++i) {
            if (sortedLogs[i].num == sortedLogs[i + 1].num && 
                sortedLogs[i + 1].num == sortedLogs[i + 2].num) {
                string numVal = sortedLogs[i].num;
                // Avoid duplicates in result if there are more than 3 consecutive
                if (result.empty() || result.back() != numVal) {
                    result.push_back(numVal);
                }
                // If we want to find all numbers that appear at least 3 times consecutively,
                // and there might be longer consecutive sequences, we should still add once
                // But we can skip ahead since we already added this num
                // However, to be efficient and correct - continue scanning
            }
        }
        return result;
    }
};
