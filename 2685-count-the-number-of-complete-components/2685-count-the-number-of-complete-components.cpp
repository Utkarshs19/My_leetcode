class Solution {
public:
    int edge=0;
    int cnt=0;

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        cnt++;

        for(auto &i:adj[node])
        {
            edge++;
            if(vis[i]==-1)
            {
                dfs(i,adj,vis);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,-1);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                edge=0;
                cnt=0;
                dfs(i,adj,vis);
                edge=edge/2;
                if(edge==((cnt*(cnt-1)/2)))ans++;

            }
        }

        return ans;

    }
};