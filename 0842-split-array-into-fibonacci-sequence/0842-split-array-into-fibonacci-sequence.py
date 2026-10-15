class Solution:
    def splitIntoFibonacci(self, num: str) -> list[int]:
        n = len(num)
        for i in range(1, min(10, n-1)):  # first number length
            if num[0] == '0' and i > 1:
                break
            first = int(num[:i])
            if first > 2**31 - 1:
                break
            for j in range(i+1, min(n, i+10)):  # second number length
                if num[i] == '0' and j-i > 1:
                    break
                second = int(num[i:j])
                if second > 2**31 - 1:
                    break
                seq = [first, second]
                k = j
                while k < n:
                    third = seq[-1] + seq[-2]
                    if third > 2**31 - 1:
                        break
                    third_str = str(third)
                    if num.startswith(third_str, k):
                        seq.append(third)
                        k += len(third_str)
                    else:
                        break
                if k == n and len(seq) >= 3:
                    return seq
        return []
