import java.util.*;

class Excel {
    private int H;
    private int W;
    private int[][] val;
    private List<List<List<int[]>>> formula; // formula[r][c] list of int[4] {r1,c1,r2,c2}

    public Excel(int height, char width) {
        this.H = height;
        this.W = width - 'A' + 1;
        this.val = new int[H][W];
        this.formula = new ArrayList<>();
        for (int i = 0; i < H; i++) {
            List<List<int[]>> row = new ArrayList<>();
            for (int j = 0; j < W; j++) {
                row.add(new ArrayList<>());
            }
            formula.add(row);
        }
    }

    private List<int[]> parse(String s) {
        List<int[]> res = new ArrayList<>();
        if (!s.contains(":")) {
            int col = s.charAt(0) - 'A';
            int row = Integer.parseInt(s.substring(1)) - 1;
            res.add(new int[]{row, col, row, col});
        } else {
            String[] parts = s.split(":");
            String left = parts[0];
            String right = parts[1];
            int c1 = left.charAt(0) - 'A';
            int r1 = Integer.parseInt(left.substring(1)) - 1;
            int c2 = right.charAt(0) - 'A';
            int r2 = Integer.parseInt(right.substring(1)) - 1;
            if (r1 > r2) {
                int tmp = r1; r1 = r2; r2 = tmp;
            }
            if (c1 > c2) {
                int tmp = c1; c1 = c2; c2 = tmp;
            }
            res.add(new int[]{r1, c1, r2, c2});
        }
        return res;
    }

    public void set(int row, char column, int val) {
        int r = row - 1;
        int c = column - 'A';
        this.val[r][c] = val;
        formula.get(r).get(c).clear();
    }

    public int get(int row, char column) {
        int r = row - 1;
        int c = column - 'A';
        List<int[]> f = formula.get(r).get(c);
        if (f.isEmpty()) {
            return val[r][c];
        }
        int total = 0;
        for (int[] rc : f) {
            int r1 = rc[0], c1 = rc[1], r2 = rc[2], c2 = rc[3];
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    total += get(i + 1, (char)('A' + j));
                }
            }
        }
        return total;
    }

    public int sum(int row, char column, String[] numbers) {
        int r = row - 1;
        int c = column - 'A';
        List<int[]> list = new ArrayList<>();
        for (String num : numbers) {
            list.addAll(parse(num));
        }
        formula.get(r).set(c, list);
        return get(row, column);
    }
}
