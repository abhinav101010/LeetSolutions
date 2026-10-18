import java.util.*;
class World { String name; int population; int area; }
class Solution {
    public List<List<String>> bigCountries(List<World> w) {
        List<List<String>> r = new ArrayList<>();
        for (World x : w) if (x.area >= 3000000 || x.population >= 25000000)
            r.add(Arrays.asList(x.name, String.valueOf(x.population), String.valueOf(x.area)));
        return r;
    }
}
