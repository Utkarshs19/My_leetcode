class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int node)
    {
        if(parent[node]!=node)
        {
            parent[node]=find(parent[node]);
        }
        return parent[node];
    }

    void join(int a,int b)
    {
        a=find(a);
        b=find(b);

        if(rank[a]<rank[b])swap(a,b);

        parent[b]=a;
        if(rank[a]==rank[b])rank[a]++;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> edges;

        int n=points.size();

        parent.resize(n);
        rank.resize(n,-1);

        for(int i=0;i<n;i++)parent[i]=i;

        int ans=0;

        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
    edges.push_back({i,j,(abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]))});
            }
        }

        // for(int i=0;i<edges.size();i++)
        // {
        //     cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
        // }

        sort(edges.begin(),edges.end(),
        [](auto &l,auto &r) {return l[2]<r[2];});

        cout<<endl<<endl;

        // for(int i=0;i<edges.size();i++)
        // {
        //     cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
        // }


        for(auto& edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if(find(u)==find(v))continue;
            join(u,v);
            ans+=wt;
        }

        
        return ans;
    }
};