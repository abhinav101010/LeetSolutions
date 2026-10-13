class Solution:
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        res = 0
        buf4 = [''] * 4
        while res < n:
            count = read4(buf4)
            if count == 0:
                break
            for i in range(count):
                if res >= n:
                    break
                buf[res] = buf4[i]
                res += 1
        return res