class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:
        def get_key(log):
            _id, rest = log.split(" ", 1)
            if rest[0].isdigit():
                return (1, )  # digit log, sort after letter logs, keep original order via stable sort? we'll assign a big index
            else:
                return (0, rest, _id)  # letter log: sort by rest then id
        # we need to keep digit logs order, so we can't just sort by key because digit logs will be sorted among themselves by rest which may change order.
        # Instead, separate.
        letter = []
        digit = []
        for log in logs:
            if log.split(" ",1)[1][0].isdigit():
                digit.append(log)
            else:
                letter.append(log)
        letter.sort(key=lambda x: (x.split(" ",1)[1], x.split(" ",1)[0]))
        return letter + digit
