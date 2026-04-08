class Solution {
public:

    vector<int> ans;
    int n;
    string labels;
    vector<int> dfs(int node,int par,vector<vector<int>> &adj)
    {
        vector<int> v(26,0);
        v[labels[node]-'a']++;

        for(auto i:adj[node])
        {
            if(i==par)continue;
            vector<int> t=dfs(i,node,adj);
            for(int j=0;j<26;j++)
            {
                v[j]+=t[j];
            }
        }

        ans[node]=v[labels[node]-'a'];

        return v;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>> adj(n);
        this->n=n;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        this->labels=labels;
        ans.resize(n);
        dfs(0,-1,adj);

        return ans;
        
    }
};