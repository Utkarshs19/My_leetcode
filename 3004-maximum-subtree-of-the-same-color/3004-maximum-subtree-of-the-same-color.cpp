class Solution {
public:
    vector<int> colors;
    int ans=0;
    vector<int> flag;
    map<int,int> m;
    int dfs(int node,vector<vector<int>> &adj,vector<int> &vis,int cnt)
    {
        vis[node]=1;
        cnt++;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                cnt+=dfs(i,adj,vis,0);

                if(colors[node]!=colors[i] || flag[i]==0)
                {
                    flag[node]=0;
                }
                
            }
        }
        m[node]=cnt;
        return cnt;
    }

    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {

        int n=edges.size()+1;
        this->colors=colors;

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        flag.resize(n,1);
        vector<int> vis(n,0);

        dfs(0,adj,vis,0);

        for(int i=0;i<n;i++)
        {
            if(flag[i])
            {
                ans=max(ans,m[i]);
            }
        }
       

        return ans;
        
    }
};