import java.util.*;

class MyNumber {
    int num;
    public MyNumber(int num) {
        this.num = num;
    }
}

class Solution {
    public int biggestSingleNumber(List<MyNumber> numbers) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (MyNumber n : numbers) {
            cnt.put(n.num, cnt.getOrDefault(n.num, 0) + 1);
        }
        int res = -1;
        for (Map.Entry<Integer, Integer> e : cnt.entrySet()) {
            if (e.getValue() == 1) {
                if (e.getKey() > res) res = e.getKey();
            }
        }
        return res;
    }
}
