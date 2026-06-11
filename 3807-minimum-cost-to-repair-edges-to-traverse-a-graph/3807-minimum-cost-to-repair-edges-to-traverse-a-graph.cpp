class Solution {
public:
    int n;
    bool helper(int node,vector<vector<pair<int,int>>> &adj,int mid,int k)
    {
        vector<int> vis(n,0);
        vis[node]=1;
        queue<int> q;
        q.push(node);
        int cnt=0;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int cur=q.front();
                q.pop();

                if(cur==n-1)
                {
                    return cnt<=k;
                }

                for(auto i:adj[cur])
                {
                    if(i.second<=mid && !vis[i.first])
                    {
                        vis[i.first]=1;
                        q.push(i.first);
                    }
                }
            }
            cnt++;
        }   
        return false;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        
        this->n=n;
        int ans=-1;
        int low=1;
        int high=1e9;

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(helper(0,adj,mid,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};