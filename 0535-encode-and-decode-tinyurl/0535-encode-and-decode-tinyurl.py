import random
import string

class Codec:
    def __init__(self):
        self.url_to_code = {}
        self.code_to_url = {}
        self.chars = string.ascii_letters + string.digits
        self.base = "http://tinyurl.com/"

    def encode(self, longUrl: str) -> str:
        if longUrl in self.url_to_code:
            return self.base + self.url_to_code[longUrl]
        code = ''.join(random.choices(self.chars, k=6))
        while code in self.code_to_url:
            code = ''.join(random.choices(self.chars, k=6))
        self.url_to_code[longUrl] = code
        self.code_to_url[code] = longUrl
        return self.base + code

    def decode(self, shortUrl: str) -> str:
        code = shortUrl.replace(self.base, "")
        return self.code_to_url.get(code, "")