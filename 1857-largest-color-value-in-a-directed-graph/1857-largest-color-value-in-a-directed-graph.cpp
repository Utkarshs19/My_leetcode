class Solution {
public:
    int n=colors.length();
    vector<int> vis,instack;
    vector<vector<int>> dp;
    string colors;

    int dfs(int node,vector<vector<int>> &adj)
    {
        if(instack[node])return 1e9;
        if(vis[node])return 0;

         vis[node]=1;
         instack[node]=1;

        dp[node][colors[node]-'a']=1;
         for(auto i:adj[node])
         {
            if(dfs(i,adj)==1e9)return 1e9;

            for(int c=0;c<26;c++)
            {
                dp[node][c]=max(dp[node][c],((c==colors[node]-'a')?1+dp[i][c]:dp[i][c]));
                
            }
         }

         instack[node]=0;
         return *max_element(dp[node].begin(),dp[node].end());
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        this->n=colors.length();
        vector<vector<int>> adj(n);
        vis.resize(n,0);
        this->colors=colors;
        instack.resize(n,0);
        dp.resize(n,vector<int>(26,0));

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
            instack.resize(n,0);
            ans=max(ans,dfs(i,adj));
            }
        }

        return (ans==1e9)?-1:ans;
        
    }
};