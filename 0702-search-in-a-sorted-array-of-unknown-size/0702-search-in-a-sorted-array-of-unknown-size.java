// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
interface ArrayReader {
    // Returns the value of the element at index i of the secret array (0-indexed).
    // If the index is out of bounds, returns 2^31 - 1.
    int get(int index);
}

class Solution {
    public int search(ArrayReader reader, int target) {
        int lo = 0, hi = 1;
        while (reader.get(hi) < target) {
            lo = hi;
            hi <<= 1; // hi *= 2
        }
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = reader.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
}
