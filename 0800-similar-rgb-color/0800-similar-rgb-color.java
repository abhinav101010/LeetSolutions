class Solution {
    public String similarRGB(String color) {
        String r = similar(color.substring(1, 3));
        String g = similar(color.substring(3, 5));
        String b = similar(color.substring(5, 7));
        return "#" + r + g + b;
    }
    private String similar(String s) {
        int val = Integer.parseInt(s, 16);
        int nearest = (int) Math.round(val / 17.0) * 17;
        if (nearest < 0) nearest = 0;
        if (nearest > 255) nearest = 255;
        int digit = nearest / 17;
        String hex = Integer.toHexString(digit);
        return hex + hex;
    }
}
