class Solution {
public:
    vector<vector<int>> ans;
    vector<set<int>> v;

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,int x)
    {
        vis[node]=1;
        
        for(auto i:adj[node])
        {
            v[x].insert(i);
            if(vis[i]==-1)
            dfs(i,adj,vis,x);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        ans.resize(n);
        v.resize(n);

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,-1);
            dfs(i,adj,vis,i);
        }

        for(int i=0;i<n;i++)
        {
            for(auto j:v[i])
            ans[i].push_back(j);
        }

        return ans;
        
    }
};