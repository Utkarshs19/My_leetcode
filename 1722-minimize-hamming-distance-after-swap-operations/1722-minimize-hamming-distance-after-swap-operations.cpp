class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node)
    {
        if(node!=parent[node])
        {
            parent[node]=(find(parent[node]));
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

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n=source.size();
        
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)parent[i]=i;

        for(int i=0;i<allowedSwaps.size();i++)
        {
            join(allowedSwaps[i][0],allowedSwaps[i][1]);
        }

        map<int,map<int,int>> m;

        for(int i=0;i<source.size();i++)
        {
            int x=find(i);
            m[x][source[i]]++;
            m[x][target[i]]--;

        }

        int ans=0;

        for (auto &g : m) {
            for (auto &x : g.second) {
                if (x.second > 0)
                    ans += x.second;
            }
        }
        

        return ans;



    }
};