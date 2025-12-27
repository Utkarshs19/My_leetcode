//  Normal Disjoint Set Union;

class Solution {
public:

    vector<int> parent,rank;

    int find(int i)
    {
        if(parent[i]!=i)
        {
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }

    void join(int a,int b)
    {
        int root_A=find(a);
        int root_B=find(b);

        if(root_A!=root_B)
        {
            if(rank[root_A]>rank[root_B])
            {
                parent[root_B]=root_A;
            }
            else if(rank[root_A]<rank[root_B])
            {
                parent[root_A]=root_B;
            }
            else
            {
                parent[root_B]=root_A;
                rank[root_A]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=1;i<=n;i++)parent[i]=i;

        for(auto& edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            if(find(u)==find(v))return edge;
            join(u,v);
        }
        
        return {};
    }   
};