import java.util.*;

class Follow {
    public int follower;
    public int followee;
    public Follow(int follower, int followee) { this.follower = follower; this.followee = followee; }
}

class Solution {
    public List<List<String>> secondDegreeFollower(List<Follow> follow) {
        TreeSet<Integer> resultSet = new TreeSet<>();
        for (Follow f1 : follow)
            for (Follow f2 : follow)
                if (f1.followee == f2.follower)
                    resultSet.add(f2.followee);
        List<List<String>> result = new ArrayList<>();
        for (int x : resultSet) result.add(Arrays.asList(String.valueOf(x)));
        return result;
    }
}
