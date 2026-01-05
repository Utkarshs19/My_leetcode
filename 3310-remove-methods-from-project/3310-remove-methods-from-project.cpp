class Solution {
public:
    set<int> st;
    bool flag=false;

    void dfs1(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        st.insert(node);

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            dfs1(i,adj,vis);
        }
    }

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        if(st.find(node)!=st.end())
        {
            flag=true;
            return;
        }

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            dfs(i,adj,vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);

        for(int i=0;i<invocations.size();i++)
        {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> vis(n,-1);

        dfs1(k,adj,vis);


        vector<int> ans;
        vis.assign(n,-1);
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())ans.push_back(i);
        }
        flag=false;
        for(int i=0;i<ans.size();i++)
        {
            if(vis[ans[i]]==-1)dfs(ans[i],adj,vis);
            
            if(flag==true)
            {
                for(auto j:st)
                ans.push_back(j);

                return ans;
            }   
        }
        return ans;
    }
};