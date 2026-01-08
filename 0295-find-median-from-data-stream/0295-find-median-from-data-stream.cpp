class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    priority_queue<int> p;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        p.push(num);

        if(!pq.empty() && p.top()>pq.top())
        {
            pq.push(p.top());
            p.pop();
        }

        if(p.size()>pq.size()+1)
        {
            pq.push(p.top());
            p.pop();
        }

        if(pq.size()>p.size()+1)
        {
            p.push(pq.top());
            pq.pop();
        }
        
    }
    
    double findMedian() {

        if(pq.size()==p.size())return (pq.top()+p.top())/2.0;
        else if(pq.size()>p.size())return pq.top();
        else return p.top();
        
    }
};
