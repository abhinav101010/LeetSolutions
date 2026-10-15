class Solution:
    def similarRGB(self, color: str) -> str:
        def similar(x):
            # x is two-digit hex string
            val = int(x, 16)
            # find nearest multiple of 17
            # multiples: 0,17,34,...,255
            # compute round to nearest multiple of 17
            # Compute int(round(val/17.0)*17)
            # but need to clamp 0-255
            nearest = int(round(val / 17.0)) * 17
            if nearest < 0:
                nearest = 0
            if nearest > 255:
                nearest = 255
            # format as two-digit hex with same digits
            # we need to output two identical hex digits representing nearest
            # Actually nearest may not be a multiple of 17 that corresponds to identical hex digits? Wait multiples of 17 in decimal correspond to hex values 0x00,0x11,0x22,...,0xFF? Let's check: 0x11 = 17 decimal, 0x22 = 34, etc. Yes because 0x11 = 1*16+1=17. So nearest multiple of 17 will be of form 0xXX where X is hex digit.
            # So we can compute hex digit = nearest / 17
            digit = nearest // 17
            # format as single hex digit then repeat
            hex_digit = format(digit, 'x')
            return hex_digit + hex_digit
        r = similar(color[1:3])
        g = similar(color[3:5])
        b = similar(color[5:7])
        return '#' + r + g + b
