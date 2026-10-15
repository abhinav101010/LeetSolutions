class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:
            # email
            s = s.lower()
            at = s.index('@')
            name = s[:at]
            domain = s[at:]
            masked_name = name[0] + '*****' + name[-1]
            return masked_name + domain
        else:
            # phone
            digits = [c for c in s if c.isdigit()]
            nd = len(digits)
            local = ''.join(digits[-10:])
            country = digits[:-10]
            if not country:
                return '***-***-' + local[-4:]
            else:
                return '+' + ('*' * len(country)) + '-***-***-' + local[-4:]
