class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        result = []
        i = 0
        n = len(words)
        
        while i < n:
            line_len = len(words[i])
            j = i + 1
            while j < n and line_len + 1 + len(words[j]) <= maxWidth:
                line_len += 1 + len(words[j])
                j += 1
            
            line_words = words[i:j]
            num_words = j - i
            
            if j == n or num_words == 1:
                # Last line or single word: left-justified
                line = ' '.join(line_words)
                line += ' ' * (maxWidth - len(line))
            else:
                # Fully justified
                total_spaces = maxWidth - sum(len(w) for w in line_words)
                spaces_between = num_words - 1
                space_per_gap = total_spaces // spaces_between
                extra_spaces = total_spaces % spaces_between
                
                line = line_words[0]
                for k in range(1, num_words):
                    spaces = space_per_gap + (1 if k <= extra_spaces else 0)
                    line += ' ' * spaces + line_words[k]
            
            result.append(line)
            i = j
        
        return result