class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        List<Integer> diff = new ArrayList<>();

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff.add(i);
            }
        }

        if (diff.isEmpty()) {
            return true;
        }

        if (diff.size() != 2) {
            return false;
        }

        int i = diff.get(0);
        int j = diff.get(1);

        return s1.charAt(i) == s2.charAt(j) && s1.charAt(j) == s2.charAt(i);
    }
}