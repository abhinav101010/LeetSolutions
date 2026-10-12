class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best(k, 0);
        for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
            vector<int> candidate = merge(maxSubsequence(nums1, i), maxSubsequence(nums2, k - i));
            if (compare(candidate, 0, best, 0) > 0) {
                best = candidate;
            }
        }
        return best;
    }
    
private:
    vector<int> maxSubsequence(const vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> stack;
        for (int num : nums) {
            while (drop > 0 && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            if ((int)stack.size() < k) {
                stack.push_back(num);
            } else {
                drop--;
            }
        }
        return stack;
    }
    
    vector<int> merge(const vector<int>& a, const vector<int>& b) {
        vector<int> result;
        result.reserve(a.size() + b.size());
        int i = 0, j = 0;
        while (i < (int)a.size() || j < (int)b.size()) {
            if (compare(a, i, b, j) > 0) {
                result.push_back(a[i++]);
            } else {
                result.push_back(b[j++]);
            }
        }
        return result;
    }
    
    int compare(const vector<int>& a, int i, const vector<int>& b, int j) {
        while (i < (int)a.size() && j < (int)b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == (int)b.size()) return 1;
        if (i == (int)a.size()) return -1;
        return a[i] - b[j];
    }
};