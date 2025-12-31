class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,int cur)
    {
        vis[node]=cur;

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis,cur);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n=s.length();

        vector<int> vis(n,-1);

        vector<vector<int>> adj(n);

        for(int i=0;i<pairs.size();i++)
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis,i);
            }
        }

        int maxi=*max_element(vis.begin(),vis.end());


        vector<string> v(maxi+1,"");

        for(int i=0;i<vis.size();i++)
        {
            v[vis[i]]+=s[i];
        }

        for(int i=0;i<v.size();i++)
        {
            sort(v[i].begin(),v[i].end());
            reverse(v[i].begin(),v[i].end());

        }

        string ans="";

        for(int i=0;i<vis.size();i++)
        {
            ans += v[vis[i]].back();
            v[vis[i]].pop_back();

        }

        return ans;        
        
    }
};