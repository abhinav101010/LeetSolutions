import java.util.*;
class Triangle { int x,y,z; }
class Solution {
    public List<List<String>> triangleJudgement(List<Triangle> t) {
        List<List<String>> r = new ArrayList<>();
        for (Triangle x : t) {
            boolean ok = x.x+x.y>x.z && x.x+x.z>x.y && x.y+x.z>x.x;
            r.add(Arrays.asList(String.valueOf(x.x),String.valueOf(x.y),String.valueOf(x.z), ok?"Yes":"No"));
        }
        return r;
    }
}
