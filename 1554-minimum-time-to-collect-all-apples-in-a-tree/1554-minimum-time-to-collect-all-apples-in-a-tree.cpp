class Solution {
public:

int ans=0;

    void dfs(int cur,map<int,vector<int>> &m ,map<int,int> &m1 , vector<bool> &vis)
    {
        vis[cur]=true;

        for(auto i:m[cur])
        {
            int size=m1.size();
            int cnt=0;

            if(!vis[i])
            {
                cnt++;
                if(m1.find(i)!=m1.end())
                m1.erase(i);
                dfs(i,m,m1,vis);
            }

            if(size !=m1.size())
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

        map<int,int> m1;

        for(int i=0;i<hasApple.size();i++)
        {
            if(hasApple[i]==true)
            m1[i]++;
        }

        vector<bool> vis(n,false);


        dfs(0,m,m1,vis);

        return ans;
        
    }
};