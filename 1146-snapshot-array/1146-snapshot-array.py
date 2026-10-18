class SnapshotArray:
    def __init__(self, length):
        self.data=[[(0,0)] for _ in range(length)]
        self.snap_id=0
    def set(self, index, val):
        self.data[index].append((self.snap_id,val))
    def snap(self):
        self.snap_id+=1
        return self.snap_id-1
    def get(self, index, snap_id):
        arr=self.data[index]
        lo,hi=0,len(arr)
        while lo<hi:
            mid=(lo+hi)//2
            if arr[mid][0]<=snap_id: lo=mid+1
            else: hi=mid
        return arr[lo-1][1]
