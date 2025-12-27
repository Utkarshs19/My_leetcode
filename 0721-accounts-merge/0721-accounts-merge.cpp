class Solution {
public:
    map<string,vector<string>> m;
    map<string,string> m1;
    map<string,bool> m2;

    vector<vector<string>> ans;

    vector<string> v;

    void dfs(string str)
    {
        m2[str]=true;
        v.push_back(str);

        for(auto i:m[str])
        {
            if(m2[i]==false)
            {
                dfs(i);
            }
        }

    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                m2[accounts[i][j]]=false;
                m1[accounts[i][j]]=accounts[i][0];
                for(int k=1;k<accounts[i].size();k++)
                {
                    m[accounts[i][j]].push_back(accounts[i][k]);
                }
            }
        }    

        for(auto i:m)
        {
            if(m2[i.first]==false)
            {
                v.push_back(m1[i.first]);
                dfs(i.first);
                sort(v.begin()+1,v.end());
                ans.push_back(v);
            }
            v.clear();
        }

        return ans;
        
    }
};