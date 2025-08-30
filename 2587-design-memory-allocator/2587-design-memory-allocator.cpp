class Allocator {
public:
    vector<int> v;
    int length;
    map<int,vector<int>> m;
    Allocator(int n) {
        length=n;
        v.resize(n);

    }
    
    int allocate(int size, int mID) {
        int cnt=0;
        int idx;

        for(int i=0;i<length;i++)
        {
            if(cnt==0)idx=i;
            if(v[i]==0)cnt++;
            else cnt=0;

            if(cnt>=size)break;
        }

        if(cnt>=size)
        {
            for(int i=idx;i<idx+size;i++)
            {
                v[i]=mID;
                m[mID].push_back(i);
            }
        }

        return cnt>=size?idx:-1;

    }
    
    int freeMemory(int mID) {

        int cnt=0;
        for(auto it:m[mID])
        {
            v[it]=0;
            cnt++;
        }
        m.erase(mID);
        return cnt;
        
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */