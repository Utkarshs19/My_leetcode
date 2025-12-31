class Solution {
public:

    map<pair<int,int>,int> m;
    int ans=INT_MAX;

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;

        for(auto &i:adj[node])
        {
            ans=min(ans,m[{node,i}]);
            ans=min(ans,m[{i,node}]);
                
            if(vis[i]==-1)
            {

                dfs(i,adj,vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        

        vector<vector<int>> adj(n+1);

        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            m[{roads[i][0],roads[i][1]}]=roads[i][2];
            m[{roads[i][1],roads[i][0]}]=roads[i][2];
        }
        vector<int> vis(n+1,-1);


        dfs(1,adj,vis);

        return ans;
        
    }
};