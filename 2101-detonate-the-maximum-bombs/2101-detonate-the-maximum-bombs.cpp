class Solution {
public:
    int cnt=0;
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        cnt++;

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            dfs(i,adj,vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n=bombs.size();
        vector<vector<int>> adj(n);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r  = bombs[i][2];

                if (dx*dx + dy*dy <= r*r) {
                    adj[i].push_back(j);  
                }
            }
        }

        

        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,-1);
            if(vis[i]==-1)
            {
                cnt=0;
                dfs(i,adj,vis);
                ans=max(ans,cnt);
            }
        }
        
        return ans;
    }
};