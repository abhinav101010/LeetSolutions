class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        MOD = 1337
        
        def mod_pow(x: int, y: int) -> int:
            result = 1
            x %= MOD
            while y:
                if y & 1:
                    result = (result * x) % MOD
                x = (x * x) % MOD
                y >>= 1
            return result
        
        result = 1
        for digit in b:
            result = mod_pow(result, 10) * mod_pow(a, digit) % MOD
        return result