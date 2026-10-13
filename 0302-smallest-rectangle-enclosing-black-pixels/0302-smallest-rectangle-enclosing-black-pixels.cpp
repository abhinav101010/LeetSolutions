class Solution {
public:
    bool hasBlack(vector<vector<char>>& image, int mid, bool isCol) {
        if (isCol) {
            for (int i = 0; i < image.size(); i++) {
                if (image[i][mid] == '1') return true;
            }
        } else {
            for (int j = 0; j < image[0].size(); j++) {
                if (image[mid][j] == '1') return true;
            }
        }
        return false;
    }
    
    int searchLeft(vector<vector<char>>& image, int low, int high, bool isCol) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasBlack(image, mid, isCol)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    int searchRight(vector<vector<char>>& image, int low, int high, bool isCol) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasBlack(image, mid, isCol)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = searchLeft(image, 0, y, true);
        int right = searchRight(image, y, image[0].size() - 1, true);
        int top = searchLeft(image, 0, x, false);
        int bottom = searchRight(image, x, image.size() - 1, false);
        return (right - left + 1) * (bottom - top + 1);
    }
};