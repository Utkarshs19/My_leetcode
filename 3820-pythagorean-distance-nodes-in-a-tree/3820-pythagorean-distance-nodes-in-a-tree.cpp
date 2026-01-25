class Solution {
public:

    vector<long long> bfs(int src,vector<vector<int>> &adj)
    {
        vector<long long> dist(adj.size(),INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int u=q.front();q.pop();

            for(auto i:adj[u])
            {
                if(dist[i]==INT_MAX)
                {
                    dist[i]=1+dist[u];
                    q.push(i);
                }

            }
        }
        return dist;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<long long> dx=bfs(x,adj);
        vector<long long> dy=bfs(y,adj);
        vector<long long> dz=bfs(z,adj);

        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<long long> d{dx[i],dy[i],dz[i]};
            sort(d.begin(),d.end());

            if((d[0]*d[0])+(d[1]*d[1])==(d[2]*d[2]))ans++;
        }

        return ans;
        
    }
};