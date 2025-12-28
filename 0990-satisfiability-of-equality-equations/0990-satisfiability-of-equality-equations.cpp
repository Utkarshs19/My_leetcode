class Solution {
public:
    map<char,vector<char>> m;
    map<char,bool> m1;

    void dfs(char c,map<char,vector<char>> &m ,map<char,bool>& m1)
    {
        m1[c]=true;

        for(auto i:m[c])
        {
            if(m1[i]==false)
            {
                dfs(i,m,m1);
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {

        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                m[equations[i][0]].push_back(equations[i][3]);
                m[equations[i][3]].push_back(equations[i][0]);
            }
            m1[equations[i][0]]=false;
            m1[equations[i][3]]=false;
        }

        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
                for(auto& j:m1)j.second=false;

                if(m1[equations[i][0]]==false)
                {
                    dfs(equations[i][0],m,m1);
                }
                if(m1[equations[i][3]]==true)
                {
                    return false;
                }
            
            }
        }

        return true;

        
    }
};