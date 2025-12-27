class Solution {
public:

    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,int &size)
    {
        vis[node]=1;
        size++;

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            {
                dfs(i,vis,adj,size);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        long long ans=0;


        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n,-1);
        vector<long long> v;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                int size=0;
                dfs(i,vis,adj,size);
                v.push_back(size);
            }
        }

        if(v.size()==1)return 0;

        for(int i=0;i<v.size();i++)
        {
            ans+=(v[i]*(n-v[i]));
            n=n-v[i];
        }

        return ans;
        
    }
};