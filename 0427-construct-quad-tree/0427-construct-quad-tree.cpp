/**
 * Definition for a QuadTree node.
 * class Node {
 * public:
 *     bool val;
 *     bool isLeaf;
 *     Node* topLeft;
 *     Node* topRight;
 *     Node* bottomLeft;
 *     Node* bottomRight;
 *     Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
 *     Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
 *     Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
 * };
 */
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size(), grid.size());
    }
    
private:
    Node* build(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int val = isUniform(grid, r1, c1, r2, c2);
        if (val != -1) {
            return new Node(val == 1, true);
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
    
    int isUniform(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int val = grid[r1][c1];
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                if (grid[i][j] != val) return -1;
            }
        }
        return val;
    }
};