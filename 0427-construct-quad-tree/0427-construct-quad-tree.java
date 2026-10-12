/**
 * Definition for a QuadTree node.
 * class Node {
 *     public boolean val;
 *     public boolean isLeaf;
 *     public Node topLeft;
 *     public Node topRight;
 *     public Node bottomLeft;
 *     public Node bottomRight;
 *     public Node() {}
 *     public Node(boolean _val, boolean _isLeaf) {
 *         val = _val;
 *         isLeaf = _isLeaf;
 *     }
 *     public Node(boolean _val, boolean _isLeaf, Node _topLeft, Node _topRight, Node _bottomLeft, Node _bottomRight) {
 *         val = _val;
 *         isLeaf = _isLeaf;
 *         topLeft = _topLeft;
 *         topRight = _topRight;
 *         bottomLeft = _bottomLeft;
 *         bottomRight = _bottomRight;
 *     }
 * };
 */
import java.util.*;

class Solution {
    public Node construct(int[][] grid) {
        return build(grid, 0, 0, grid.length, grid.length);
    }
    
    private Node build(int[][] grid, int r1, int c1, int r2, int c2) {
        Boolean val = isUniform(grid, r1, c1, r2, c2);
        if (val != null) {
            return new Node(val, true, null, null, null, null);
        }
        
        int midR = (r1 + r2) / 2;
        int midC = (c1 + c2) / 2;
        
        return new Node(
            true,
            false,
            build(grid, r1, c1, midR, midC),
            build(grid, r1, midC, midR, c2),
            build(grid, midR, c1, r2, midC),
            build(grid, midR, midC, r2, c2)
        );
    }
    
    private Boolean isUniform(int[][] grid, int r1, int c1, int r2, int c2) {
        int val = grid[r1][c1];
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                if (grid[i][j] != val) return null;
            }
        }
        return val == 1;
    }
}