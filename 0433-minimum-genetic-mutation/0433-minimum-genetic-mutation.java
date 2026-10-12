import java.util.*;

class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
        if (!bankSet.contains(endGene)) return -1;
        
        Queue<String> queue = new LinkedList<>();
        queue.offer(startGene);
        Set<String> visited = new HashSet<>();
        visited.add(startGene);
        int steps = 0;
        char[] genes = {'A', 'C', 'G', 'T'};
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String gene = queue.poll();
                if (gene.equals(endGene)) return steps;
                
                for (int j = 0; j < 8; j++) {
                    for (char g : genes) {
                        if (g != gene.charAt(j)) {
                            String newGene = gene.substring(0, j) + g + gene.substring(j + 1);
                            if (bankSet.contains(newGene) && !visited.contains(newGene)) {
                                visited.add(newGene);
                                queue.offer(newGene);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
}