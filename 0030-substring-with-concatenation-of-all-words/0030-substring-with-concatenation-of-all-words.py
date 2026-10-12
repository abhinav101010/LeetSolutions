from collections import Counter, defaultdict
from typing import List

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        total_len = word_len * len(words)
        n = len(s)
        
        if n < total_len:
            return []
        
        word_count = Counter(words)
        result = []
        
        for i in range(word_len):
            left = i
            count = 0
            current_count = defaultdict(int)
            
            for j in range(i, n - word_len + 1, word_len):
                word = s[j:j + word_len]
                
                if word in word_count:
                    current_count[word] += 1
                    count += 1
                    
                    while current_count[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        current_count[left_word] -= 1
                        count -= 1
                        left += word_len
                    
                    if count == len(words):
                        result.append(left)
                else:
                    current_count.clear()
                    count = 0
                    left = j + word_len
        
        return result