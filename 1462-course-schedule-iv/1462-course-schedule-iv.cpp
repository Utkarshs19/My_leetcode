class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,int target)
    {
        vis[node] = 1;

        for (auto nxt : adj[node]) {
            if (nxt == target) {
                vis[target] = 1;
                return;
            }
            if(vis[nxt]==-1)
            dfs(nxt, adj, vis, target);
            if (vis[target] == 1) return;
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<bool> ans;

        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<queries.size();i++)
        {
            vector<int> vis(numCourses,-1);

            dfs(queries[i][0],adj,vis,queries[i][1]);

            if(vis[queries[i][1]]==-1)
            ans.push_back(false);
            else
            ans.push_back(true);
        }

        return ans;
        
    }
};