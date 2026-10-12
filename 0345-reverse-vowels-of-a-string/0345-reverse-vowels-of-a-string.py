class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a', 'e', 'i', 'o', 'u',
                  'A', 'E', 'I', 'O', 'U']
        arr = list(s)
        l, r = 0, len(arr) - 1
        while l < r:
            while l < r and arr[l] not in vowels:
                l += 1
            while l < r and arr[r] not in vowels:
                r -= 1
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
        return "".join(arr)