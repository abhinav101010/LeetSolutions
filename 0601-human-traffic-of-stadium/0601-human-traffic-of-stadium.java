import java.util.ArrayList;
import java.util.List;

class Stadium {
    int id;
    String visit_date;
    int people;
}

class Solution {
    public List<Stadium> humanTraffic(List<Stadium> stadium) {
        List<Stadium> result = new ArrayList<>();
        int n = stadium.size();
        boolean[] mark = new boolean[n];
        for (int i = 0; i <= n - 3; i++) {
            if (stadium.get(i).people >= 100 && 
                stadium.get(i+1).people >= 100 && 
                stadium.get(i+2).people >= 100 &&
                stadium.get(i+1).id == stadium.get(i).id + 1 && 
                stadium.get(i+2).id == stadium.get(i+1).id + 1) {
                mark[i] = mark[i+1] = mark[i+2] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (mark[i]) result.add(stadium.get(i));
        }
        return result;
    }
}
