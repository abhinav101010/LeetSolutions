class Solution {
    public List<List<Integer>> shiftGrid(List<List<Integer>> grid, int k) {
        int rows = grid.size();
        int cols = grid.get(0).size();
        int totalItems = rows * cols;

        k %= totalItems;
        if (k == 0) {
            return grid;
        }

        List<Integer> flat = new ArrayList<>();
        for (List<Integer> row : grid) {
            flat.addAll(row);
        }

        List<Integer> newGrid = new ArrayList<>(flat);
        newGrid.addAll(flat);

        int startPoint = totalItems - k;

        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();

        for (int i = startPoint; i < startPoint + totalItems; i++) {
            curr.add(newGrid.get(i));
            if (curr.size() == cols) {
                ans.add(new ArrayList<>(curr));
                curr.clear();
            }
        }

        return ans;
    }
}