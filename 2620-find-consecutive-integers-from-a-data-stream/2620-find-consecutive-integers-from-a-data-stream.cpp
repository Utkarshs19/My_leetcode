class DataStream {
public:
    int v,k1;
    map<int,int> m;
    list<int> l;
    DataStream(int value, int k) {
        v=value;
        k1=k;
    }
    
    bool consec(int num) {

        l.push_back(num);
        m[num]++;

        while(l.size()>k1)
        {
            m[l.front()]--;
            l.pop_front();
        }

        if(l.size()<k1)return false;
        if(m[v]<k1)return false;
        return true;

        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */