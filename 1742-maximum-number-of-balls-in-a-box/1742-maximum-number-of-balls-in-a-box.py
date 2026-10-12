class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        boxes = {}

        for num in range(lowLimit, highLimit + 1):
            temp = num
            digit_sum = 0

            while temp > 0:
                digit_sum += temp % 10
                temp //= 10

            boxes[digit_sum] = boxes.get(digit_sum, 0) + 1

        return max(boxes.values())