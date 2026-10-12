/*
Word Frequency - Shell solution:
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{print $2, $1}'
*/

class Solution {
public:
    string wordFrequency() {
        return "cat words.txt | tr -s ' ' '\\n' | sort | uniq -c | sort -nr | awk '{print $2, $1}'";
    }
};