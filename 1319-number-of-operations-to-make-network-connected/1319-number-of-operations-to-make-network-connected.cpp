class Solution {
public:
    int cnt=0;
    int edges=0;

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        cnt++;

        for(auto &i:adj[node])
        {
            edges++;
            if(vis[i]==-1)
            {
                dfs(i,adj,vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n,-1);

        int components=0;
        int extra=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {   
                components++;
                cnt=0;
                edges=0;
                dfs(i,adj,vis);

                edges=edges/2;
                if(edges>cnt-1)
                {
                    extra+=edges-cnt+1;
                }
            }
        }

        if(extra>=components-1)
        return components-1;

        return -1;        
    }
};