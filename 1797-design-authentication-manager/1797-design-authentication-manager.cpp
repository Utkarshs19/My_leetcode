class AuthenticationManager {
public:
    int time;
    map<string,int> m;
    AuthenticationManager(int timeToLive) {
        time=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {

        m[tokenId]=currentTime+time;
        
    }
    
    void renew(string tokenId, int currentTime) {

        if(m.find(tokenId)!=m.end())
        {
            if(m[tokenId]<=currentTime)
            {
                m.erase(tokenId);
            }
            else
            m[tokenId]=currentTime+time;
        }
        
    }
    
    int countUnexpiredTokens(int currentTime) {

        int cnt=0;

        for (auto it = m.begin(); it != m.end(); ) {
        if (it->second <= currentTime) {
            it = m.erase(it);   // ✅ safe erase
        } else {
            cnt++;
            ++it;
        }
    }
    return cnt;
        
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */