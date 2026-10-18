import java.util.*;

class Insurance { int pid; long tiv2015; long tiv2016; double lat; double lon; }

class Solution {
    public long investments2016(List<Insurance> insurance) {
        Map<Long, Integer> tivCount = new HashMap<>();
        Map<String, Integer> locCount = new HashMap<>();
        for (Insurance ins : insurance) {
            tivCount.merge(ins.tiv2015, 1, Integer::sum);
            String key = Double.toString(ins.lat) + "|" + Double.toString(ins.lon);
            locCount.merge(key, 1, Integer::sum);
        }
        long sum = 0;
        for (Insurance ins : insurance) {
            if (tivCount.get(ins.tiv2015) > 1) {
                String key = Double.toString(ins.lat) + "|" + Double.toString(ins.lon);
                if (locCount.get(key) == 1) sum += ins.tiv2016;
            }
        }
        return sum;
    }
}
