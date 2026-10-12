import java.util.*;

class NumArray {
    private int n;
    private int[] tree;
    
    public NumArray(int[] nums) {
        n = nums.length;
        tree = new int[2 * n];
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    
    public void update(int index, int val) {
        int i = index + n;
        tree[i] = val;
        while (i > 1) {
            i >>= 1;
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    
    public int sumRange(int left, int right) {
        int res = 0;
        left += n;
        right += n;
        while (left <= right) {
            if ((left & 1) == 1) {
                res += tree[left];
                left++;
            }
            if ((right & 1) == 0) {
                res += tree[right];
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return res;
    }
}