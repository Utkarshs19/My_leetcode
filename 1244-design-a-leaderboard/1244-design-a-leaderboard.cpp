class Leaderboard {
public:
    map<int,int> m;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        m[playerId]+=score;
    }
    
    int top(int K) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:m)
        {
            pq.push(i.second);
            if(pq.size()>K)pq.pop();
        }
        long long ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
    
    void reset(int playerId) {
        m[playerId]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */