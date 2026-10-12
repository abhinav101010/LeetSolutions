class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length;
        int n = boxGrid[0].length;
        
        // Rotate 90 degrees clockwise
        char[][] rotated = new char[n][m];
        for (int col = 0; col < n; col++) {
            for (int r = 0; r < m; r++) {
                rotated[col][r] = boxGrid[m - 1 - r][col];
            }
        }
        
        // Apply gravity
        for (int col = 0; col < m; col++) {
            int writeRow = n - 1;
            for (int readRow = n - 1; readRow >= 0; readRow--) {
                if (rotated[readRow][col] == '*') {
                    writeRow = readRow - 1;
                } else if (rotated[readRow][col] == '#') {
                    if (writeRow != readRow) {
                        rotated[writeRow][col] = '#';
                        rotated[readRow][col] = '.';
                    }
                    writeRow--;
                }
            }
        }
        
        return rotated;
    }
}