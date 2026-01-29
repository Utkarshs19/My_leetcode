class Solution {
public:
    
    int bfs(int node,vector<vector<int>> &adj,int k)
    {
        unordered_set<int> st;
        st.insert(node);
        queue<int> q;
        q.push(node);

        while(k>0)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front();q.pop();
                for(auto u:adj[x])
                {
                    if(!st.count(u))
                    {
                        st.insert(u);
                        q.push(u);
                    }
                }
                
            }
            k--;
        }

        return st.size();
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int n1=edges1.size()+1;
        int n2=edges2.size()+1;

        vector<vector<int>> adj1(n1);
        vector<vector<int>> adj2(n2);

        for(int i=0;i<edges1.size();i++)
        {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }

         for(int i=0;i<edges2.size();i++)
        {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }
        vector<int> v1,v2;
        for(int i=0;i<n1;i++)
        {
            v1.push_back(bfs(i,adj1,k));
        }

        int maxi=0;

         for(int i=0;i<n2;i++)
        {
            if(k-1>=0)
            maxi=max(maxi,bfs(i,adj2,k-1));
        }

        vector<int> ans;

        for(int i=0;i<v1.size();i++)
        {
            ans.push_back(v1[i]+maxi);
        }

        return ans;





    }
};