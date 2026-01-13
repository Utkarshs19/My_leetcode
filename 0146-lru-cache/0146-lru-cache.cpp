class LRUCache {
public:
    // list.splice(postition_to_move, source_list, list_iterator_initial_position)
    int sz=0;
    map<int,pair<int,list<int>::iterator>> m;
    list<int> lst;

    LRUCache(int capacity) {

        sz=capacity;
        
    }
    
    int get(int key) {

        if(m.count(key))
        {
            lst.splice(lst.begin(),lst,m[key].second);
            return m[key].first;
        }
        else
        return -1;
        
    }
    
    void put(int key, int value) {

        if(m.count(key))
        {
            lst.splice(lst.begin(),lst,m[key].second);
            m[key].first=value;
        }
        else
        {
            lst.push_front(key);

            if(lst.size()>sz)
            {
                m.erase(lst.back());
                lst.pop_back();
            }
            m[key]={value,lst.begin()};
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */