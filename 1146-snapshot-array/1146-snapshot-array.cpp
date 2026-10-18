class SnapshotArray {
    vector<vector<pair<int,int>>> data; int snap_id=0;
public:
    SnapshotArray(int length): data(length, {{0,0}}) {}
    void set(int index, int val){ data[index].push_back({snap_id,val}); }
    int snap(){ return snap_id++; }
    int get(int index, int snap_id){
        auto&arr=data[index];
        int lo=0, hi=arr.size();
        while(lo<hi){int mid=(lo+hi)/2; if(arr[mid].first<=snap_id) lo=mid+1; else hi=mid;}
        return arr[lo-1].second;
    }};
