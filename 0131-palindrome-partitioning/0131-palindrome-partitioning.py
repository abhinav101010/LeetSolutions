class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # ans = []
        # i = 0
        # while i<len(s):
        #     left = i
        #     right = left+1
        #     while right < len(s):
        #         palindrome = True
        #         while left<right:
        #             if s[left] != s[right]:
        #                 palindrome = False
        #                 break
        #             left+=1
        #             right-=1
        #         if palindrome:
        #             ans.append(s[left:right+1])
        #             i = right+1
        #             break
        #         right+=1
        #     i+=1
        # print(ans)

        
        ans = []
        def isPalindrome(left, right):
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True
        def dfs(start, path):
            if start == len(s):
                ans.append(path[:])
                return
            for end in range(start, len(s)):
                if isPalindrome(start, end):
                    path.append(s[start:end + 1])
                    dfs(end + 1, path)
                    path.pop()
        dfs(0, [])
        return ans