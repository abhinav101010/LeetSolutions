import java.util.*;

class RangeModule {
    private TreeMap<Integer, Integer> map;

    public RangeModule() {
        map = new TreeMap<>();
    }

    public void addRange(int left, int right) {
        // find first key that is >= left
        Integer lb = map.floorKey(left);
        if (lb != null && map.get(lb) >= left) {
            left = Math.min(left, map.get(lb));
        }
        // now iterate over keys starting from left while start < right
        Integer cur = map.ceilingKey(left);
        while (cur != null && cur < right) {
            int next = map.get(cur);
            right = Math.max(right, next);
            map.remove(cur);
            cur = map.ceilingKey(cur);
        }
        map.put(left, right);
    }

    public boolean queryRange(int left, int right) {
        Integer lb = map.floorKey(left);
        if (lb == null) return false;
        return map.get(lb) >= right;
    }

    public void removeRange(int left, int right) {
        Integer lb = map.floorKey(left);
        if (lb != null && map.get(lb) > left) {
            int val = map.get(lb);
            map.put(lb, left);
            if (val > right) {
                map.put(right, val);
            }
        }
        // remove all entries fully inside [left, right)
        Integer cur = map.ceilingKey(left);
        while (cur != null && cur < right) {
            int next = map.get(cur);
            map.remove(cur);
            if (next > right) {
                map.put(right, next);
                break;
            }
            cur = map.ceilingKey(cur);
        }
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
