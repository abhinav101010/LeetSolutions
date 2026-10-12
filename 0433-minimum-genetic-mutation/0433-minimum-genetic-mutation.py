from collections import deque
from typing import List

class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bank_set = set(bank)
        if endGene not in bank_set:
            return -1
        
        queue = deque([(startGene, 0)])
        visited = {startGene}
        genes = ['A', 'C', 'G', 'T']
        
        while queue:
            gene, steps = queue.popleft()
            if gene == endGene:
                return steps
            
            for i in range(8):
                for g in genes:
                    if g != gene[i]:
                        new_gene = gene[:i] + g + gene[i+1:]
                        if new_gene in bank_set and new_gene not in visited:
                            visited.add(new_gene)
                            queue.append((new_gene, steps + 1))
        
        return -1