class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }


        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        vector<int> dist(n,INT_MAX);

        pq.push({0,{src,0}});
        dist[src]=0;

        while(!pq.empty())
        {
            int s=pq.top().second.first;
            int cost=pq.top().second.second;
            int stop=pq.top().first;
            pq.pop();
            
            if(stop>k)continue;

            for(auto i:adj[s])
            {
                int node=i.first;
                int c=i.second;

                if(dist[node]>c+cost && stop<=k)
                {
                    dist[node]=c+cost;
                    pq.push({stop+1,{node,c+cost}});
                }
            }

        }

        return dist[dst]==INT_MAX?-1:dist[dst];
        
    }
};