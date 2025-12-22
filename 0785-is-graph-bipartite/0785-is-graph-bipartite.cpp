class Solution {
public:
    bool ans=true;
    void dfs(int node,vector<vector<int>> &graph,vector<int> &vis,int color)
    {
        vis[node]=color;

        for(auto i:graph[node])
        {
            if(vis[i]==-1)
            {
                dfs(i,graph,vis,color^1);
                if(!ans)return;
            }
            else
            {
                if(vis[i]!=(color^1))
                {
                    cout<<i<<endl;
                    ans=false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> vis(graph.size(),-1);

        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==-1)
            dfs(i,graph,vis,0);
            
            if(!ans)return false;
        }

        return ans;
        
    }
};