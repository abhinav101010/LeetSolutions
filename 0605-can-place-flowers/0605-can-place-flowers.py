class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        length = len(flowerbed)

        for i in range(length):

            if 0 < i < length - 1:
                if flowerbed[i-1] == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
                    flowerbed[i] = 1
                    n -= 1

            elif i == 0:
                if length == 1:
                    if flowerbed[0] == 0:
                        n -= 1
                elif flowerbed[0] == 0 and flowerbed[1] == 0:
                    flowerbed[0] = 1
                    n -= 1

            elif i == length - 1:
                if flowerbed[length-1] == 0 and flowerbed[length-2] == 0:
                    flowerbed[length-1] = 1
                    n -= 1

            if n <= 0:
                return True

        return n <= 0