class SnapshotArray {
public:
    
    vector<vector<pair<int,int>>> v;
    int cnt=0;

    SnapshotArray(int length) {

        v.resize(length);

        for(int i=0;i<length;i++)
        {
            v[i].push_back({0,0});
        }   
    }
    
    void set(int index, int val) {

        v[index].push_back({cnt,val});
        
    }
    
    int snap() {

       return cnt++;

    }
    
    int get(int index, int snap_id) {

        auto &a=v[index];

        int low=0,high=a.size()-1;
        int ans;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(a[mid].first<=snap_id)
            {
                ans=a[mid].second;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return ans;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */