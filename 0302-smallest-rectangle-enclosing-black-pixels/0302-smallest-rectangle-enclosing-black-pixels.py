class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        m, n = len(image), len(image[0]) if image else 0
        left = self.first_fit(image, 0, y, True, True)
        right = self.last_fit(image, y, n - 1, True, False)
        top = self.first_fit(image, 0, x, False, True)
        bottom = self.last_fit(image, x, m - 1, False, False)
        return (right - left + 1) * (bottom - top + 1)
    
    def first_fit(self, image, low, high, is_col, find_left):
        while low <= high:
            mid = (low + high) // 2
            if self.has_black(image, mid, is_col) == find_left:
                high = mid - 1
            else:
                low = mid + 1
        return low
    
    def last_fit(self, image, low, high, is_col, find_right):
        while low <= high:
            mid = (low + high) // 2
            if self.has_black(image, mid, is_col) == find_right:
                low = mid + 1
            else:
                high = mid - 1
        return high
    
    def has_black(self, image, mid, is_col):
        if is_col:
            for i in range(len(image)):
                if image[i][mid] == '1':
                    return True
            return False
        else:
            for j in range(len(image[0]) if image else 0):
                if image[mid][j] == '1':
                    return True
            return False