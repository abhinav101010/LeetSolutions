class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        data = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        diffWays = set()
        for word in words:
            morseCode = ""
            for c in word:
                morseCode += data[ord(c)-ord('a')]
            diffWays.add(morseCode)
        return len(diffWays)