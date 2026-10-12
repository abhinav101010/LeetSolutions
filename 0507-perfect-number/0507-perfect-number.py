class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        # divisors = [1]
        # for i in range(2,num):
        #     if num%i == 0:
        #         divisors.append(i)
        # return sum(divisors) == num

        if num <= 1:
            return False

        divisors = [1]

        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                divisors.append(i)

                if i != num // i:
                    divisors.append(num // i)

        return sum(divisors) == num