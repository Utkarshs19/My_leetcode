class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }

    }
    
    int query(int left, int right, int value) {

        auto it=m.find(value);
        if(it==m.end())return 0;

        auto low=lower_bound(it->second.begin(),it->second.end(),left);
        auto high=upper_bound(it->second.begin(),it->second.end(),right);

        return high-low;
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */