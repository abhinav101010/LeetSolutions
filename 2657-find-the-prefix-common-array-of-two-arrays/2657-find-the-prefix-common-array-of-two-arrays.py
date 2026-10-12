class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans = []
        for i in range(n):
            arrA = A[:i+1]
            arrB = B[:i+1]

            common=0
            for num in arrA:
                if num in arrB:
                    common+=1
            ans.append(common)
        return ans