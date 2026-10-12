/*
Tenth Line - Shell solution:
sed -n '10p' file.txt
OR
awk 'NR==10' file.txt
*/

import java.util.*;

class Solution {
    public String tenthLine() {
        return "sed -n '10p' file.txt";
    }
}