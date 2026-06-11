class Solution {
public:
    map<int,vector<int>> m;
    map<int,int> m1;
    vector<int> value;
    set<int> st;
    void dfs1(int node)
    {
        st.insert(node);
        for(auto i:m[node])
        {
            if(!st.count(i))
            dfs1(i);
        }
    }
    int dfs(int node,int sum,vector<int> &vis)
    {
        vis[node]=1;

        for(auto i:m[node])
        {
            if(!vis[i])
            {
                sum+=dfs(i,0,vis);
            }
        }
        sum+=value[node];
        m1[node]=sum;
        return sum;
    }

    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        
        this->value=value;
        for(int i=0;i<parent.size();i++)
        {
            m[parent[i]].push_back(i);
        }
        vector<int> vis(nodes,0);
        dfs(0,0,vis);

        for(auto i:m1)
        {
           if(i.second==0)
           {
                if(!st.count(i.first))
                dfs1(i.first);
           }
        }

        return nodes-st.size();
    }
};