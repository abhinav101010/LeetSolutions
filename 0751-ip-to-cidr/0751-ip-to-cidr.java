import java.util.*;

class Solution {
    public List<String> ipToCIDR(String ip, int n) {
        long ipNum = ipToInt(ip);
        List<String> res = new ArrayList<>();
        while (n > 0) {
            // lowbit
            long lowbit = ipNum & -ipNum;
            // adjust to not exceed n
            while (lowbit > n) {
                lowbit >>= 1;
            }
            int prefix = 32 - (int)(Math.log(lowbit) / Math.log(2));
            res.add(intToIp(ipNum) + "/" + prefix);
            ipNum += lowbit;
            n -= lowbit;
        }
        return res;
    }
    
    private long ipToInt(String ip) {
        String[] parts = ip.split("\\.");
        long res = 0;
        for (String p : parts) {
            res = res * 256 + Integer.parseInt(p);
        }
        return res;
    }
    
    private String intToIp(long x) {
        return ((x >> 24) & 255) + "." +
               ((x >> 16) & 255) + "." +
               ((x >> 8) & 255) + "." +
               (x & 255);
    }
}
