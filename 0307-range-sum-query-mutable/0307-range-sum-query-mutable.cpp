class NumArray {
private:
    int n;
    vector<int> tree;
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    
    void update(int index, int val) {
        int i = index + n;
        tree[i] = val;
        while (i > 1) {
            i >>= 1;
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        left += n;
        right += n;
        while (left <= right) {
            if (left & 1) {
                res += tree[left];
                left++;
            }
            if (!(right & 1)) {
                res += tree[right];
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return res;
    }
};