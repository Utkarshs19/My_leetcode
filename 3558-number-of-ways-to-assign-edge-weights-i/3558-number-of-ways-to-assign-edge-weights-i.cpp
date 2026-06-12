class Solution {
public:
    const int mod=1e9+7;
    int dfs(int node,int par,vector<vector<int>> &adj)
    {
        int d=0;
        for(auto i:adj[node])
        {
            if(i==par)continue;
            d=max(d,1+dfs(i,node,adj));
        }
        return d;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n=edges.size()+1;

        vector<vector<int>> adj(n+1);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int max_deapth=dfs(1,-1,adj);
        
        long long ans=1;
        for(int i=0;i<max_deapth-1;i++)
        {
            ans=(ans*2)%mod;
        }

        return ans;
    }
};