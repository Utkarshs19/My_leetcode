class Solution {
public:
    map<string,vector<string>> m;

    void dfs(string node,map<string,vector<string>> &m ,map<string,bool> &m1,int &cnt)
    {
        cnt++;
        m1[node]=true;

        for(auto i:m[node])
        {
            if(!m1.count(i))
            {
                dfs(i,m,m1,cnt);
            }
        }
    }

    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {

        for(int i=0;i<regions.size();i++)
        {
            string str=regions[i][0];

            for(int j=1;j<regions[i].size();j++)
            {
                m[str].push_back(regions[i][j]);
            }
        }
        int size=1e9;
        string ans;

        for(auto i:m)
        {
            map<string,bool> m1;
            int cnt=0;
            dfs(i.first,m,m1,cnt);

            if(m1.count(region1) && m1.count(region2))
            {
                cout<<i.first<<"  "<<size<<"  "<<cnt<<endl;
                if(size>cnt)
                {
                    size=cnt;
                    ans=i.first;
                }
            }
        }

        return ans;

    }
};