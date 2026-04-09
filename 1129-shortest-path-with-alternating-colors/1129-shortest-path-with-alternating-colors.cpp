class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int> ans(n,-1);

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<redEdges.size();i++)
        {
            adj[redEdges[i][0]].push_back({redEdges[i][1],1});
        }
        for(int i=0;i<blueEdges.size();i++)
        {
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],0});
        }
        
        int step=0;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(2,0));
        vis[0][0]=1;
        vis[0][1]=1;
        
        q.push({0,0});
        q.push({0,1});

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int node=q.front().first;
                int color=q.front().second;
                q.pop();
                
                if(ans[node]==-1)
                ans[node]=step;

                for(auto [n,c]:adj[node])
                {
                    if(c==color)continue;
                    if(vis[n][c])continue;

                    vis[n][c]=1;
                    q.push({n,c});
                    
                }
                
            }
            step++;
        }

        return ans;

    }
};