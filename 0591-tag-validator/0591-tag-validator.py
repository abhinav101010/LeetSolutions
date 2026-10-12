import re

class Solution:
    def isValid(self, code: str) -> bool:
        # Check if the entire code is wrapped in a valid closed tag
        if not code.startswith('<') or not code.endswith('>'):
            return False
        
        i = 1
        if i >= len(code) or code[i] == '/':
            return False
        
        # Parse tag name
        tag_name = ''
        while i < len(code) and code[i] != '>':
            tag_name += code[i]
            i += 1
        
        if i >= len(code) or not tag_name or len(tag_name) > 9 or not tag_name.isupper():
            return False
        
        if code[i] != '>':
            return False
        
        i += 1
        
        # Parse content
        content = code[i:-len(tag_name)-3]  # remove closing tag
        
        # Check for invalid tags in content
        j = 0
        while j < len(content):
            if content[j] == '<':
                if j + 1 < len(content) and content[j+1] == '!':
                    # CDATA
                    if not content.startswith('<![CDATA[', j):
                        return False
                    end = content.find(']]>', j + 9)
                    if end == -1:
                        return False
                    j = end + 3
                elif j + 1 < len(content) and content[j+1] == '/':
                    # Closing tag
                    return False  # No closing tags allowed in content for single root
                else:
                    # Opening tag
                    end = content.find('>', j)
                    if end == -1:
                        return False
                    inner_tag = content[j+1:end]
                    if not inner_tag or len(inner_tag) > 9 or not inner_tag.isupper():
                        return False
                    j = end + 1
            else:
                j += 1
        
        # Check closing tag
        closing = f"</{tag_name}>"
        if not code.endswith(closing):
            return False
        
        return True