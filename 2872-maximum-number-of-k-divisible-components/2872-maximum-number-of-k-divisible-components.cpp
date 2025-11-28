class Solution {
public:
    int ans=0;

    long long dfs(int node,int par,vector<vector<int>> &adj,vector<int>&values,int k)
    {
        long long sum=values[node];

        for(auto cur:adj[node])
        {
            if(cur==par)continue;
            sum+=dfs(cur,node,adj,values,k);
        }

        if(sum%k==0)
        {
            ans++;
            return 0;
        }
        return sum;

    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0,-1,adj,values,k);

        return ans;
        
    }
};