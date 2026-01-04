class Solution {
public:

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        for(int i=1;i<=4;i++)
        {
            bool flag=false;
            for(auto x:adj[node])
            {
                if(vis[x]==i)
                {
                    flag=true;
                    break;
                }
            }
            if(flag==false)
            {
                vis[node]=i;
                break;
            }
        }

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n+1);

        for(int i=0;i<paths.size();i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }

        vector<int> vis(n+1,-1);

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis);
            }
        }
        vis.erase(vis.begin());
        return vis;
        
    }
};