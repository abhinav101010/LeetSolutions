class SnapshotArray {
    List<int[]>[] data; int snap_id=0;
    @SuppressWarnings("unchecked")
    public SnapshotArray(int length){ data=new List[length]; for(int i=0;i<length;i++){data[i]=new ArrayList<>(); data[i].add(new int[]{0,0});} }
    public void set(int index, int val){ data[index].add(new int[]{snap_id,val}); }
    public int snap(){ return snap_id++; }
    public int get(int index, int snap_id){
        int[] arr=data[index].stream().mapToInt(a->a[0]).toArray(); // placeholder
        // binary search
        java.util.List<int[]> lst=data[index]; int lo=0,hi=lst.size();
        while(lo<hi){int mid=(lo+hi)/2; if(lst.get(mid)[0]<=snap_id) lo=mid+1; else hi=mid;}
        return lst.get(lo-1)[1];
    }}
