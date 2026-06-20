class FirstUnique {
public:
    unordered_set<int> st;
    unordered_map<int,int> m;
    list<int> l;
    int i=0;
    FirstUnique(vector<int>& nums) {
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            if(i.second==1)st.insert(i.first);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i]))
            {
                l.push_back(nums[i]);
            }
        }
    }
    
    int showFirstUnique() {

       while(!l.empty() && !st.count(l.front()))
       {
            l.pop_front();
       }

        if(l.size())
        return l.front();
        
        return -1;
    }
    
    void add(int value) {
        
       m[value]++;

       if(m[value]==1)
       {
        l.push_back(value);
        st.insert(value);
       }
       else if(m[value]>1)
        st.erase(value);

    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */