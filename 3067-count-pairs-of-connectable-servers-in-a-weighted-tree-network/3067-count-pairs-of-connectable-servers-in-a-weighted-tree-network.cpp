class Solution {
public:

    int signalSpeed;

    int dfs(int node,int par,vector<vector<pair<int,int>>> &adj,int dist)
    {
        int cnt=(dist%signalSpeed==0);

        for(auto [i,d]:adj[node])
        {
            if(i==par)continue;

            cnt+=dfs(i,node,adj,dist+d);
        }

        return cnt;

    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        
        int n=edges.size()+1;
        this->signalSpeed=signalSpeed;
        vector<int> ans(n);

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        for(int i=0;i<n;i++)
        {
            int sum=0;

            for(auto [x,d]:adj[i])
            {
                int cnt=dfs(x,i,adj,d);

                ans[i]+=(cnt*sum);
                sum+=cnt;
            }
        }

        return ans;



    }
};