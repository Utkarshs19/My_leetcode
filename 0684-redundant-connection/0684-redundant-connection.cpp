class Solution {
public:

    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,int a,int b)
    {
        vis[node]=1;

        for(auto i:adj[node])
        {
            if(node==a && i==b || node==b&&i==a)continue;

            if(vis[i]==-1)
            {
                dfs(i,vis,adj,a,b);
            }

        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int x=-1;
        int y=-1;

        vector<int> ans;

        int n=edges.size();

        vector<vector<int>> adj(n+1);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            int cc=0;

            vector<int> vis(n+1,-1);

            for(int j=1;j<n+1;j++)
            {
                if(vis[j]==-1)
                {
                    cc++;
                    dfs(j,vis,adj,edges[i][0],edges[i][1]);
                }
            }


            if(cc==1)
            {
                x=edges[i][0];
                y=edges[i][1];
            }
        }
        
        ans.push_back(x);
        ans.push_back(y);

        return ans;
    }
};