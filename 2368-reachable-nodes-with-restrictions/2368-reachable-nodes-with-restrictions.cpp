class Solution {
public:
    set<int> s;
    int cnt=0;

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        cnt++;

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            {
                if(s.find(i)!=s.end())continue;
                dfs(i,adj,vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        for(int i=0;i<restricted.size();i++)s.insert(restricted[i]);

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,-1);

        dfs(0,adj,vis);

        return cnt;
    }
};