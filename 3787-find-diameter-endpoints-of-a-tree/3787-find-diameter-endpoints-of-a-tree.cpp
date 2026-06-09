class Solution {
public:
    string findSpecialNodes(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        string ans(n,'0');

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,0);
        queue<int> q;
        int level=0;
        q.push(0);
        vis[0]=1;
        set<int> st;

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

        set<int> st1;

        for(auto i:st)
        {
            queue<int> q;
            q.push(i);
            vector<int> vis(n,0);
            vis[i]=1;
            
            set<int> s;

            while(!q.empty())
            {
                s.clear();
                int size=q.size();
                for(int i=0;i<size;i++)
                {
                    int cur=q.front();
                    s.insert(cur);
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
            }

            for(auto i:s)
            {
                st1.insert(i);
            }

        }

        for(int i=0;i<n;i++)
        {
            if(st1.count(i) || st.count(i))
            {
                ans[i]='1';
            }
        }

        return ans;

         
        
    }
};