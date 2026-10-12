class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        if self.isIPv4(queryIP):
            return "IPv4"
        if self.isIPv6(queryIP):
            return "IPv6"
        return "Neither"
    
    def isIPv4(self, ip: str) -> bool:
        parts = ip.split('.')
        if len(parts) != 4:
            return False
        for part in parts:
            if not part or len(part) > 3 or (part[0] == '0' and len(part) > 1):
                return False
            if not part.isdigit():
                return False
            val = int(part)
            if val < 0 or val > 255:
                return False
        return True
    
    def isIPv6(self, ip: str) -> bool:
        parts = ip.split(':')
        if len(parts) != 8:
            return False
        for part in parts:
            if not part or len(part) > 4:
                return False
            for ch in part:
                if not (ch.isdigit() or 'a' <= ch.lower() <= 'f'):
                    return False
        return True