class Solution {
public:

    int ans=INT_MAX;

    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int> &vis)
    {
        vis[node]=1;

        for(auto &i:adj[node])
        {        
            ans=min(ans,i.second);
                     
            if(vis[i.first]==-1)
            {

                dfs(i.first,adj,vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
           
        }
        vector<int> vis(n+1,-1);


        dfs(1,adj,vis);

        return ans;
        
    }
};