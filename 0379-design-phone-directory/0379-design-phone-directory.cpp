class PhoneDirectory {
public:
    map<int,int> m;
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++)
        {
            m[i]=-1;
        }
    }
    
    int get() {
        
        if(!m.size())return -1;
        
        int x=m.begin()->first;

        m.erase(x);

        return x;

    }
    
    bool check(int number) {
        
        if(m.count(number))return true;
        return false;

    }
    
    void release(int number) {
        
        m[number]=-1;

    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */