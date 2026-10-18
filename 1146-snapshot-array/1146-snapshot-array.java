import java.util.*;

class SnapshotArray {
    List<int[]>[] data;
    int snapId;
    @SuppressWarnings("unchecked")
    public SnapshotArray(int length) {
        data = new List[length];
        for (int i = 0; i < length; i++) {
            data[i] = new ArrayList<>();
            data[i].add(new int[]{0, 0});
        }
        snapId = 0;
    }
    public void set(int index, int val) {
        data[index].add(new int[]{snapId, val});
    }
    public int snap() {
        return snapId++;
    }
    public int get(int index, int snapId) {
        List<int[]> arr = data[index];
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid)[0] <= snapId) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return arr.get(left - 1)[1];
    }
}
