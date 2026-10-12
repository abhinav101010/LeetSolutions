class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        
        int s1Count = 0;
        int s2Count = 0;
        int index = 0;
        unordered_map<int, pair<int, int>> recall;
        
        while (s1Count < n1) {
            s1Count++;
            for (char ch : s1) {
                if (ch == s2[index]) {
                    index++;
                    if (index == (int)s2.size()) {
                        s2Count++;
                        index = 0;
                    }
                }
            }
            
            if (recall.count(index)) {
                auto prev = recall[index];
                int preLoopS1 = prev.first;
                int preLoopS2 = prev.second;
                int inLoopS1 = s1Count - preLoopS1;
                int inLoopS2 = s2Count - preLoopS2;
                
                if (inLoopS1 > 0) {
                    int remaining = n1 - preLoopS1;
                    int loops = remaining / inLoopS1;
                    s1Count = preLoopS1 + loops * inLoopS1;
                    s2Count = preLoopS2 + loops * inLoopS2;
                }
            } else {
                recall[index] = {s1Count, s2Count};
            }
        }
        
        return s2Count / n2;
    }
};