class Solution {
public:

    vector<int> ans;
    string s;
    vector<int> last;
    vector<int> parent;
    void dfs(int node,int par,vector<vector<int>> &adj)
    {
        int c=s[node]-'a';

        int nearestAncestor=last[c];

        last[c]=node;

        for(auto i:adj[node])
        {
            dfs(i,node,adj);
        }

        int newParent=(nearestAncestor!=-1)?nearestAncestor:parent[node];
        last[c]=nearestAncestor;

        if(newParent!=-1)
        {
            ans[newParent]+=ans[node];
        }

    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
        int n=s.length();
        ans.resize(n,1);
        this->s=s;
        this->parent=parent;

        last.resize(26,-1);

        vector<vector<int>> adj(n);

        for(int i=1;i<parent.size();i++)
        {
            adj[parent[i]].push_back(i);
        }

        dfs(0,-1,adj);

        return ans;
        
    }
};