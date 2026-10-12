class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # uglyNumberSets = {1}
        # i=1
        # while len(uglyNumberSets) < n:
        #     uglyNumberSets.add(i*2)
        #     uglyNumberSets.add(i*3)
        #     uglyNumberSets.add(i*5)
        #     i+=1
        # print(uglyNumberSets)
        # return list(uglyNumberSets)[n-1]


        ugly = [1]

        i2 = i3 = i5 = 0

        for _ in range(1, n):
            next2 = ugly[i2] * 2
            next3 = ugly[i3] * 3
            next5 = ugly[i5] * 5

            nextUgly = min(next2, next3, next5)
            ugly.append(nextUgly)

            if nextUgly == next2:
                i2 += 1

            if nextUgly == next3:
                i3 += 1

            if nextUgly == next5:
                i5 += 1

        return ugly[-1]