class Solution {
public:

    void dfs(int node,vector<vector<pair<int,int>>> &adj,int mid,vector<int> &vis,int threshold)
    {
        vis[node]=1;
        for(auto [next,wt]:adj[node])
        {
            if(wt>mid)continue;
            if(!vis[next])
            {
                dfs(next,adj,mid,vis,threshold);
            }
        }

    }

    bool helper(int mid,vector<vector<pair<int,int>>> &adj,int n,int threshold)
    {
        vector<int> vis(n,0);

        dfs(0,adj,mid,vis,threshold);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])return false;
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<pair<int,int>>> adj(n);
        int high=INT_MIN;
        int low=INT_MAX;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            high=max(high,edges[i][2]);
            low=min(low,edges[i][2]);
        }

        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(helper(mid,adj,n,threshold))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return ans;
        
    }
};