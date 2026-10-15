#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < fruits.size(); right++) {
            int fruit = fruits[right];
            count[fruit]++;
            while (count.size() > 2) {
                int left_fruit = fruits[left];
                count[left_fruit]--;
                if (count[left_fruit] == 0) {
                    count.erase(left_fruit);
                }
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
