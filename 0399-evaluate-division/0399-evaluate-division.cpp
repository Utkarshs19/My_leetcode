class Solution {
public:

    double bfs(string src,string tar,map<string,vector<pair<string,double>>> &m)
    {
        if(!m.count(src) || !m.count(tar))return -1.0;

        set<string> st;
        queue<pair<string,double>> q;
        q.push({src,1.0});
        st.insert(src);

        while(!q.empty())
        {
            auto [node,val]=q.front();
            q.pop();

            if(node==tar)return val;

            for(auto [n,v]:m[node])
            {
                if(!st.count(n))
                {
                    st.insert(n);
                    q.push({n,val*v});
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        vector<double> ans;

        map<string,vector<pair<string,double>>> m;

        for(int i=0;i<equations.size();i++)
        {
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }

        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(bfs(queries[i][0],queries[i][1],m));
        }

        return ans;
        
    }
};