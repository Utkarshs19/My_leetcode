class PhoneDirectory {
public:
    queue<int> q;
    vector<int> v;
    PhoneDirectory(int maxNumbers) {
        
        v.resize(maxNumbers,0);
        for(int i=0;i<maxNumbers;i++)
        {
            q.push(i);
        }

    }
    
    int get() {
        
        if(!q.size())return -1;

        int x=q.front();
        v[x]=1;
        q.pop();

        return x;
    }
    
    bool check(int number) {
        
        return (v[number]==0)?true:false;

    }
    
    void release(int number) {
        
        if(v[number])
        {
            v[number]=0;
            q.push(number);
        }

    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */