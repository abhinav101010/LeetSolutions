from collections import defaultdict
from typing import List

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        content_to_files = defaultdict(list)
        
        for path in paths:
            parts = path.split(' ')
            directory = parts[0]
            for file_info in parts[1:]:
                filename, content = file_info.split('(')
                content = content[:-1]  # Remove trailing ')'
                content_to_files[content].append(directory + '/' + filename)
        
        return [files for files in content_to_files.values() if len(files) > 1]