class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        prefixGcd = []
        mxi = 0
        for num in nums:
            mxi = max(mxi, num)
            prefixGcd.append(gcd(num, mxi))
        prefixGcd.sort()
        print(prefixGcd)

        ans = 0
        left = 0
        right = len(prefixGcd)-1
        while left<=right:
            if left == right:
                break
            ans+=gcd(prefixGcd[left],prefixGcd[right])
            left+=1
            right-=1
        return ans