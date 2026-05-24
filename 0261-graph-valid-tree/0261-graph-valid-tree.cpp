class Solution {
public:
    vector<int> vis;
    bool flag=false;
    
    void dfs(int node,int par,vector<vector<int>> &adj)
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,node, adj);
            }
            else
            {
                if(i!=par){
                flag=true;
                return;
                }
            }
        }
    }
    

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        
            vis.resize(n,0);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,-1,adj);
            }
        }

        return cnt==1 && !flag;
        
    }
};