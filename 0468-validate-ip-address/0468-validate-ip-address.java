class Solution {
    public String validIPAddress(String queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        if (isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
    
    private boolean isIPv4(String ip) {
        String[] parts = ip.split("\\.", -1);
        if (parts.length != 4) return false;
        for (String part : parts) {
            if (part.isEmpty() || part.length() > 3 || (part.charAt(0) == '0' && part.length() > 1)) {
                return false;
            }
            if (!part.matches("\\d+")) return false;
            int val = Integer.parseInt(part);
            if (val < 0 || val > 255) return false;
        }
        return true;
    }
    
    private boolean isIPv6(String ip) {
        String[] parts = ip.split(":", -1);
        if (parts.length != 8) return false;
        for (String part : parts) {
            if (part.isEmpty() || part.length() > 4) return false;
            for (char ch : part.toCharArray()) {
                if (!Character.isDigit(ch) && !('a' <= Character.toLowerCase(ch) && Character.toLowerCase(ch) <= 'f')) {
                    return false;
                }
            }
        }
        return true;
    }
}