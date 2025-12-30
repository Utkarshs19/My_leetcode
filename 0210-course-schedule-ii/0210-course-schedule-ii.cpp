class Solution {
public:
    vector<bool> vis;
    vector<bool> instack;
    vector<int> ans;
    bool cycle=false;

    void dfs(int node,vector<vector<int>> &adj)
    {
        vis[node]=true;
        instack[node]=true;

        for(auto& i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,adj);
            }
            else
            {
                if(instack[i]==true)
                cycle=true;
            }
        }
        instack[node]=false;
        ans.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vis.resize(numCourses,false);
        instack.resize(numCourses,false);

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj);
            }
        }

        reverse(ans.begin(),ans.end());

        if(cycle==true)return {};
        return ans;

        
    }
};