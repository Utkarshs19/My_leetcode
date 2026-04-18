class Solution {
public:

    vector<int> parent;
    vector<int> rank;
    map<int,int> m;
    int find(int node)
    {
        if(node!=parent[node])
        {
            parent[node]=find(parent[node]);
        }
        return parent[node];
    }

    void join(int u,int v)
    {
        u=find(u);
        v=find(v);

        if(rank[u]<rank[v])swap(u,v);
        parent[v]=u;
        if(rank[u]==rank[v])rank[u]++;

    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++)parent[i]=i;

        for(int i=1;i<=n;i++)
        {
            int f=threshold+1;

            while(f<=i)
            {
                if(i%f==0)
                {
                    if(m.count(f))
                    {
                        join(i,m[f]);
                    }
                    else
                    m[f]=i;
                }
                f=f+1;
            }
        }

        vector<bool> ans;

        for(int i=0;i<queries.size();i++)
        {
            if(find(queries[i][0])==find(queries[i][1]))ans.push_back(true);
            else
            ans.push_back(false);
        }

        return ans;

    }
};