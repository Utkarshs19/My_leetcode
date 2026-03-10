class FreqStack {
public:
    int i=0;
    priority_queue<vector<int>> pq;
    map<int,int> m;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        pq.push({m[val],i++,val});
    }
    
    int pop() {
        auto top=pq.top();
        pq.pop();
        m[top[2]]--;
        return top[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */