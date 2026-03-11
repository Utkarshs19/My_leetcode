class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<int> deg(n,0);

        if(n==1)return {0};

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)q.push(i);
        }

        while(!q.empty())
        {
            int size=q.size();
            if(n<=2)break;
            for(int i=0;i<size;i++)
            {
                int node=q.front();
                q.pop();
                n--;
                for(auto j:adj[node])
                {
                    deg[j]--;
                    if(deg[j]==1)q.push(j);
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;


        
    }
};