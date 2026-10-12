/*
Tenth Line - Shell solution:
sed -n '10p' file.txt
OR
awk 'NR==10' file.txt
*/

class Solution {
public:
    string tenthLine() {
        return "sed -n '10p' file.txt";
    }
};