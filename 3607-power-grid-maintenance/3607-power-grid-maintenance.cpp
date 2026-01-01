class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    int find(int node)
    {
        if(node!=parent[node])
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
     
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        parent.resize(c+1);
        rank.resize(c+1,0);

        for(int i=1;i<=c;i++)parent[i]=i;

        set<int> st;

        for(int i=0;i<connections.size();i++)
        {
            join(connections[i][0],connections[i][1]);
        }

        map<int,set<int>> m;

        for(int i=1;i<=c;i++)
        {
            m[find(i)].insert(i);
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]==1)
            {
                auto &s=m[find(queries[i][1])];
                if(s.size()==0)
                {
                    ans.push_back(-1);
                }
                else if(s.find(queries[i][1])!=s.end())
                {
                    ans.push_back(queries[i][1]);
                }
                else
                {
                    ans.push_back(*s.begin());
                }
            }
            else if(queries[i][0]==2)
            {
                m[find(queries[i][1])].erase(queries[i][1]);
            } 
        }

        return ans;

    }
};