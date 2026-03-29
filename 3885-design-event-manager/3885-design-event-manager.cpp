class EventManager {
public:

    map<int,int> m;
    priority_queue<pair<int,int>> pq;

    EventManager(vector<vector<int>>& events) {
        
        for(int i=0;i<events.size();i++)
        {
            m[events[i][0]]=events[i][1];
            pq.push({events[i][1],-1*events[i][0]});
        }

    }
    
    void updatePriority(int eventId, int newPriority) {
        
        m[eventId]=newPriority;
        pq.push({newPriority,-1*eventId});

    }
    
    int pollHighest() {

        if(m.size()==0)return -1;

        int high=-1;        
        int id;
        while(!pq.empty())
        {
            high=pq.top().first;
            id=pq.top().second*-1;

            if(m[-1*pq.top().second]!=high)pq.pop();
            else break;
            
        }

        if(pq.size()==0)return -1;
        m.erase(id);

        return id;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */