class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<int> ans;
        vector<int> dist(n,INT_MAX);
        
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            if(d>=disappear[node])continue;
            if(d>dist[node])continue;

            for(auto v:adj[node])
            {
                int x=v.first;
                int y=v.second;

                if(d+y>=disappear[x])continue;

                if(dist[x]>d+y)
                {
                    dist[x]=d+y;
                    pq.push({dist[x],x});
                }
            }
        }

        for(int i=0;i<dist.size();i++)
        {
            if(dist[i]==INT_MAX)ans.push_back(-1);
            else ans.push_back(dist[i]);
        }

        return ans;
        
    }
};