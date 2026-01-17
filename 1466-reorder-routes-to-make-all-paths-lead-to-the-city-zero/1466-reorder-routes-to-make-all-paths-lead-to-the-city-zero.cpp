class Solution {
public:
    set<pair<int,int>> st;
    int ans=0;
    vector<int> vis;

    void dfs(int node,vector<vector<int>>& adj)
    {
        vis[node]=1;

        for(auto i:adj[node])
        {
            
            if(!vis[i]){
            if(st.count({node,i}))ans++;
            dfs(i,adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);
        vis.resize(n,0);

        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            st.insert({connections[i][0],connections[i][1]});
        }

        dfs(0,adj);

        return ans;
        
    }
};