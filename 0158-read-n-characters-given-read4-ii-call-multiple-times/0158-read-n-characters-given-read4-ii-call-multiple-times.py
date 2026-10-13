class Solution:
    def __init__(self):
        self.buf4 = [''] * 4
        self.i = 0
        self.n4 = 0
        
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        res = 0
        while res < n:
            if self.i < self.n4:
                buf[res] = self.buf4[self.i]
                res += 1
                self.i += 1
            else:
                self.n4 = read4(self.buf4)
                self.i = 0
                if self.n4 == 0:
                    break
        return res