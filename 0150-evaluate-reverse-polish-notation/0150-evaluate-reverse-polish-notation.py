class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # Self Thought and implemented logic, STAND PROUD
        calculatedList = []

        for token in tokens:
            if token == "+":
                first = calculatedList.pop()
                second = calculatedList.pop()
                calculatedList.append(second + first)

            elif token == "-":
                first = calculatedList.pop()
                second = calculatedList.pop()
                calculatedList.append(second - first)

            elif token == "*":
                first = calculatedList.pop()
                second = calculatedList.pop()
                calculatedList.append(second * first)

            elif token == "/":
                first = calculatedList.pop()
                second = calculatedList.pop()
                calculatedList.append(int(second / first))

            else:
                calculatedList.append(int(token))

        return calculatedList[-1]