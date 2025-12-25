class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<double> v(n,-1.0);
        v[start_node]=1.0;
        priority_queue<pair<double,int>> pq;

        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            int node=pq.top().second;
            double prob=pq.top().first;
            pq.pop();
            cout<<node<<"  "<<prob<<endl;
            if(prob<v[node])continue;

            for(auto &[i,p]:adj[node])
            {
                double x=v[i];
                
                if(x<prob*p)
                {
                    v[i]=prob*p;
                    pq.push({v[i],i});
                }
                
            }
        }

        return v[end_node]==-1.0?0.0:v[end_node];
        
    }
};