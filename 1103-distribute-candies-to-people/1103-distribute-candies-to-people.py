class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people

        i = 0

        while candies > 0:
            give = min(candies, i + 1)

            ans[i % num_people] += give

            candies -= give
            i += 1

        return ans