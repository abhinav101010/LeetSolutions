import java.util.*;

class Solution {
    public int[][] outerTrees(int[][] trees) {
        if (trees.length <= 1) return trees;
        
        Arrays.sort(trees, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        
        List<int[]> lower = new ArrayList<>();
        for (int[] p : trees) {
            while (lower.size() >= 2 && cross(lower.get(lower.size()-2), lower.get(lower.size()-1), p) < 0) {
                lower.remove(lower.size() - 1);
            }
            lower.add(p);
        }
        
        List<int[]> upper = new ArrayList<>();
        for (int i = trees.length - 1; i >= 0; i--) {
            int[] p = trees[i];
            while (upper.size() >= 2 && cross(upper.get(upper.size()-2), upper.get(upper.size()-1), p) < 0) {
                upper.remove(upper.size() - 1);
            }
            upper.add(p);
        }
        
        Set<List<Integer>> hull = new HashSet<>();
        for (int i = 0; i < lower.size() - 1; i++) hull.add(Arrays.asList(lower.get(i)[0], lower.get(i)[1]));
        for (int i = 0; i < upper.size() - 1; i++) hull.add(Arrays.asList(upper.get(i)[0], upper.get(i)[1]));
        
        int[][] result = new int[hull.size()][2];
        int idx = 0;
        for (List<Integer> p : hull) {
            result[idx++] = new int[]{p.get(0), p.get(1)};
        }
        return result;
    }
    
    private int cross(int[] o, int[] a, int[] b) {
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
    }
}