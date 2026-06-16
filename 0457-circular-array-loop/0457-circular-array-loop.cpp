class Solution {
public:
    vector<int> vis,instack;
    bool cycle=false;

    void dfs(int node,vector<vector<int>> &adj)
    {
        vis[node]=1;
        instack[node]=1;

        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,adj);
            }
            else
            {
                if(instack[i])cycle=true;
            }
        }
        instack[node]=false;
    }



    bool circularArrayLoop(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            int nxt = ((i + nums[i]) % n + n) % n;
            if(nxt == i) continue;

            if(nums[i] * nums[nxt] > 0)
            {
                adj[i].push_back(nxt);
            }
        }
        vis.resize(n,0);
        instack.resize(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj);
            }
        }     

        return cycle;   
    }
};