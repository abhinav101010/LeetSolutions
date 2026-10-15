class FileSystem:

    def __init__(self):
        self.store = {"/": None}  # root

    def createPath(self, path: str, value: int) -> bool:
        if path in self.store:
            return False
        # find parent
        i = path.rfind('/')
        if i == -1:
            parent = "/"
        else:
            parent = path[:i]
            if parent == "":
                parent = "/"
        if parent not in self.store:
            return False
        self.store[path] = value
        return True

    def get(self, path: str) -> int:
        return self.store.get(path, -1)
