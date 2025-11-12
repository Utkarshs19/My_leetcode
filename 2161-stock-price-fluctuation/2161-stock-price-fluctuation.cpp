class StockPrice {
public:
    map<int,int> m;
    priority_queue<pair<int,int>> pq;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p; 

    int cur;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {

        m[timestamp]=price;

        pq.push({price,timestamp});

        p.push({price,timestamp});

        if (cur == -1 || timestamp >= cur)
            cur = timestamp;

    }
    
    int current() {

        return m[cur];
        
    }
    
    int maximum() {

        while(!pq.empty())
        {
            pair<int,int> q=pq.top();

            if(m[q.second]!=q.first)
            pq.pop();
            else
            return q.first;

        }
        
        return -1;
    }
    
    int minimum() {

        while(!p.empty())
        {
            pair<int,int> q=p.top();

            if(m[q.second]!=q.first)
            p.pop();
            else
            return q.first;
        }

        return -1;
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */