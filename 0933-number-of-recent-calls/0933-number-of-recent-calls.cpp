class RecentCounter {
public:
    vector<int> v;
    int i=0;
    RecentCounter() {
        
    }
    
    int ping(int t) {

        v.push_back(t);
     

        while(v[i]<t-3000)
        {
            i++;
        }
        return v.size()-i;

        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */