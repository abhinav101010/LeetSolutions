# 2666-allow-one-function-call

class Solution:
    def once(self, fn):
        """
        :type fn: Callable[[int], int]
        :rtype: Callable[[int], int]
        """
        self._called = False
        def wrapper(x):
            if self._called:
                return 0
            self._called = True
            return fn(x)
        return wrapper
