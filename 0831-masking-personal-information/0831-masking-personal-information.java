class Solution {
    public String maskPII(String s) {
        if (s.contains("@")) {
            s = s.toLowerCase();
            int at = s.indexOf('@');
            String name = s.substring(0, at);
            String domain = s.substring(at);
            String maskedName = name.charAt(0) + "*****" + name.charAt(name.length()-1);
            return maskedName + domain;
        } else {
            StringBuilder digits = new StringBuilder();
            for (char c : s.toCharArray()) {
                if (Character.isDigit(c)) {
                    digits.append(c);
                }
            }
            String dig = digits.toString();
            int n = dig.length();
            String local = dig.substring(n-10);
            String country = dig.substring(0, n-10);
            if (country.isEmpty()) {
                return "***-***-" + local.substring(6);
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append('+');
                for (int i = 0; i < country.length(); i++) {
                    sb.append('*');
                }
                sb.append("-***-***-");
                sb.append(local.substring(6));
                return sb.toString();
            }
        }
    }
}
