class Solution {
public:
    vector<int> parent,rank;
    map<int,int> m;
    int count;

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

        if(u==v)return;

        if(rank[u]<rank[v])swap(u,v);
        parent[v]=u;
        if(rank[u]==rank[v])
        rank[u]++;

        count--;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        count=n;
        
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        parent[i]=i;

        for(int i=0;i<n;i++)
        {
            int f=2;
            while(f*f<=nums[i])
            {
                if(nums[i]%f==0)
                {
                    if(m.count(f))
                    {
                        join(i,m[f]);
                    }
                    else
                    {
                        m[f]=i;
                    }
                    while(nums[i]%f==0)
                    nums[i]=nums[i]/f;
                }
                f=f+1;
            }
            if(nums[i]>1)
            {
                if(m.count(nums[i]))
                {
                    join(i,m[nums[i]]);
                }
                else
                {
                    m[nums[i]]=i;
                }
            }
        }

        return count==1;
    }
};