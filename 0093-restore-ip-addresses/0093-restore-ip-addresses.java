class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        backtrack(s, 0, 0, sb, ans);
        return ans;
    }

    private void backtrack(String s, int index, int dots, StringBuilder sb, List<String> ans) {
        if (dots == 3) {
            if (index < s.length()) {
                String last = s.substring(index);
                if (valid(last)) {
                    sb.append(last);
                    ans.add(sb.toString());
                    sb.delete(sb.length() - last.length(), sb.length());
                }
            }
            return;
        }

        int len = sb.length();
        for (int take = 1; take <= 3 && index + take < s.length(); take++) {
            String part = s.substring(index, index + take);
            if (!valid(part)) {
                break;
            }
            sb.append(part).append('.');
            backtrack(s, index + take, dots + 1, sb, ans);
            sb.setLength(len);
        }
    }

    private boolean valid(String part) {
        if (part.length() > 3) {
            return false;
        }
        if (part.length() > 1 && part.charAt(0) == '0') {
            return false;
        }
        return Integer.parseInt(part) <= 255;
    }
}
