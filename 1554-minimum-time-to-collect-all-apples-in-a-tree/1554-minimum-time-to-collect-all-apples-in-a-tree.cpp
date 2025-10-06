class Solution {
public:

int ans=0;

    void dfs(int cur,map<int,vector<int>> &m ,set<int> &s , vector<bool> &vis)
    {
        vis[cur]=true;

        for(auto i:m[cur])
        {
            int size=s.size();
            int cnt=0;

            if(!vis[i])
            {
                cnt++;
                if(s.find(i)!=s.end())
                s.erase(i);
                dfs(i,m,s,vis);
            }

            if(size !=s.size())
            ans+=(2*cnt);
        }


    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {


        map<int,vector<int>> m;

        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }

        set<int> s;

        for(int i=0;i<hasApple.size();i++)
        {
            if(hasApple[i]==true)
            s.insert(i);
        }

        vector<bool> vis(n,false);


        dfs(0,m,s,vis);

        return ans;
        
    }
};