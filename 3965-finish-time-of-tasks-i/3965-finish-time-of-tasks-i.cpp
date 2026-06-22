class Solution {
public:
    vector<int> baseTime;
    long long dfs(int node,vector<vector<int>> &adj)
    {
        if(adj[node].size()==0)return baseTime[node];
        
        long long maxi=0;
        long long mini=1e18;
        
        for(auto i:adj[node])
        {
            long long x=dfs(i,adj);
            mini=min(mini,x);
            maxi=max(maxi,x);

        }

        return maxi+maxi-mini+baseTime[node];

    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }   
        this->baseTime=baseTime;

        return dfs(0,adj);


        
    }
};