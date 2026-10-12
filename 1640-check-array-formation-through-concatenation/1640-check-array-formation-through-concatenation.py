class Solution:
    def canFormArray(self, arr, pieces):
        i = 0

        while i < len(arr):
            found = False

            for piece in pieces:
                if piece[0] == arr[i]:
                    if arr[i:i + len(piece)] != piece:
                        return False

                    i += len(piece)
                    found = True
                    break

            if not found:
                return False

        return True