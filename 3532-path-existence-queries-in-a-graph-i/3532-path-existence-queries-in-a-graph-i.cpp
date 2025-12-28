class Solution {
public:

    void dfs(int node,vector<vector<int>> &adj,vector<int>&vis,int cur)
    {
        vis[node]=cur;

        for(auto& i:adj[node])
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis,cur);
            }
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<vector<int>> edges;
        vector<vector<int>> adj(n);


        for(int i=1;i<nums.size();i++)
        {
            if(abs(nums[i]-nums[i-1])<=maxDiff)
            {
                adj[i].push_back(i-1);
                adj[i-1].push_back(i);
            }
        }

        vector<int> vis(n,-1);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis,i);
            }
        }

        vector<bool> ans;

        for(int i=0;i<queries.size();i++)
        {
            if(vis[queries[i][0]]==vis[queries[i][1]])ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
        

    }
};