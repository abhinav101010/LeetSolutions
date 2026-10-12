class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        // Find median using nth_element
        vector<int> copy = nums;
        nth_element(copy.begin(), copy.begin() + n / 2, copy.end());
        int median = copy[n / 2];
        
        // 3-way partition with virtual indexing
        auto A = [&](int i) -> int& {
            return nums[(1 + 2 * i) % (n | 1)];
        };
        
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (A(i) > median) {
                swap(A(left++), A(i++));
            } else if (A(i) < median) {
                swap(A(right--), A(i));
            } else {
                i++;
            }
        }
    }
};