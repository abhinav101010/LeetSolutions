class Solution {
    public String solveEquation(String equation) {
        String[] parts = equation.split("=");
        int[] left = count(parts[0]);
        int[] right = count(parts[1]);
        
        int coeff = left[0] - right[0];
        int constant = right[1] - left[1];
        
        if (coeff == 0 && constant == 0) return "Infinite solutions";
        if (coeff == 0 && constant != 0) return "No solution";
        int x = constant / coeff;
        return "x=" + x;
    }
    
    private int[] count(String exp) {
        int coeff = 0, constant = 0;
        int i = 0, n = exp.length();
        while (i < n) {
            char c = exp.charAt(i);
            if (c == '+' || c == '-') {
                i++;
                if (i == n) break;
            }
            int sign = (c == '-') ? -1 : 1;
            if (c == '+' || c == '-') {
                c = exp.charAt(i);
            }
            if (Character.isDigit(c)) {
                int j = i;
                while (j < n && Character.isDigit(exp.charAt(j))) j++;
                int num = Integer.parseInt(exp.substring(i, j));
                if (j < n && exp.charAt(j) == 'x') {
                    coeff += sign * num;
                    i = j + 1;
                } else {
                    constant += sign * num;
                    i = j;
                }
            } else if (c == 'x') {
                coeff += sign;
                i++;
            } else {
                i++;
            }
        }
        return new int[]{coeff, constant};
    }
}