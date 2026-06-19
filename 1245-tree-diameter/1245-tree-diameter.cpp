class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {

        int n=edges.size()+1;

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        vector<int> vis(n,0);
        set<int> st;
        q.push(0);
        vis[0]=1;

        while(!q.empty())
        {
            int size=q.size();
            st.clear();
            for(int i=0;i<size;i++)
            {
                int cur=q.front();
                q.pop();

                st.insert(cur);
                for(auto i:adj[cur])
                {
                    if(!vis[i])
                    {
                        vis[i]=1;
                        q.push(i);
                    }
                }

            }
        }

        int a=*st.begin();

        vis.assign(n,0);
        int ans=0;

        q.push(a);
        vis[a]=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int cur=q.front();
                q.pop();

                for(auto i:adj[cur])
                {
                    if(!vis[i])
                    {
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
            ans++;
        }

        return ans-1;
    }
};