class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

        dist[k]=0;

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        pq.push({0,k});

        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            for(auto i:adj[node])
            {
                if(dist[i.first]>dist[node]+i.second)
                {
                    dist[i.first]=dist[node]+i.second;
                    pq.push({dist[i.first],i.first});
                }

            }

        }

        int time=*max_element(dist.begin()+1,dist.end());

        return time==INT_MAX?-1:time;


        
    }
};