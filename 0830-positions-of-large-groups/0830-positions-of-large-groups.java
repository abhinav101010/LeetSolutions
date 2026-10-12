class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> ans = new ArrayList<>();
        int start = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (i == s.length() || s.charAt(i) != s.charAt(i - 1)) {
                int end = i - 1;
                if (end - start + 1 >= 3) {
                    ans.add(Arrays.asList(start, end));
                }
                start = i;
            }
        }
        return ans;
    }
}