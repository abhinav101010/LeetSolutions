class Solution:
    def sortPeople(self, names, heights):
        idx = list(range(len(heights)))
        idx.sort(key=lambda i: -heights[i])
        return [names[i] for i in idx]
