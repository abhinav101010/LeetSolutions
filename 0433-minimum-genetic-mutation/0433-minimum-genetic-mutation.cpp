class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1;
        
        queue<string> q;
        q.push(startGene);
        unordered_set<string> visited = {startGene};
        int steps = 0;
        char genes[4] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string gene = q.front();
                q.pop();
                if (gene == endGene) return steps;
                
                for (int j = 0; j < 8; j++) {
                    for (char g : genes) {
                        if (g != gene[j]) {
                            string newGene = gene;
                            newGene[j] = g;
                            if (bankSet.count(newGene) && !visited.count(newGene)) {
                                visited.insert(newGene);
                                q.push(newGene);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};