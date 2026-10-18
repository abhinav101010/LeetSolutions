// 2619-array-prototype-last
import java.util.*;

class Solution {
    public int last(int[] arr) {
        if (arr == null || arr.length == 0) return -1;
        return arr[arr.length - 1];
    }
}
