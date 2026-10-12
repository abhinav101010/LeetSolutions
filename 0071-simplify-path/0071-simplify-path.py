import re

class Solution:
    def simplifyPath(self, path: str) -> str:
        folders = [x for x in re.split(r'(/)', path) if x]

        if folders and folders[-1] == "/":
            folders.pop()

        i = 0
        while i < len(folders):

            # Remove duplicate slashes
            if i > 0 and folders[i] == "/" and folders[i - 1] == "/":
                folders.pop(i)
                continue

            # Remove "/folder/.."
            if folders[i] == "..":
                if i >= 2:
                    folders.pop(i)      # ..
                    folders.pop(i - 1)  # /
                    folders.pop(i - 2)  # folder

                    # Remove preceding slash if present
                    if i - 3 >= 0 and folders[i - 3] == "/":
                        folders.pop(i - 3)

                    i = max(i - 3, 0)
                    continue
                else:
                    folders.pop(i)
                    i = max(i - 1, 0)
                    continue

            # Remove "."
            if folders[i] == ".":
                folders.pop(i)
                if i > 0 and folders[i - 1] == "/":
                    folders.pop(i - 1)
                    i = max(i - 2, 0)
                continue

            i += 1

        if len(folders)>2 and folders[-1] == "/": folders.pop()
        return "".join(folders) if folders else "/"