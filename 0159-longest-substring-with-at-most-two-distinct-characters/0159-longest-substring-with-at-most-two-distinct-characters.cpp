#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> count;
        int left = 0, res = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            while (count.size() > 2) {
                count[s[left]]--;
                if (count[s[left]] == 0) {
                    count.erase(s[left]);
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};