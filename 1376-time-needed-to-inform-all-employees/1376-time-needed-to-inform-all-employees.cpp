class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]==-1)continue;
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        
        int ans=0;
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto[cur,time]=q.front();
                q.pop();
                
                int total=time+informTime[cur];
                ans=max(ans,total);
                
                for(auto j:adj[cur])
                {
                    q.push({j,total});
                }
                
            }
        }
        
        return ans;
    }
};