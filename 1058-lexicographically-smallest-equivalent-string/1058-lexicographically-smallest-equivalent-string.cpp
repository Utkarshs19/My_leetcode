class Solution {
public:

    char dfs(unordered_map<char,vector<char>> &m,char ch,vector<int> &vis)
    {
        vis[ch-'a']=1;
        char mini=ch;

        for(auto v:m[ch])
        {
            if(vis[v-'a']==0)
            mini=min(mini,dfs(m,v,vis));
        }

        return mini;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        unordered_map<char,vector<char>> m;

        for(int i=0;i<s1.length();i++)
        {
            m[s1[i]].push_back(s2[i]);
            m[s2[i]].push_back(s1[i]);
        }

        string ans="";

        for(int i=0;i<baseStr.length();i++)
        {
            vector<int> vis(26,0);

            char mini=dfs(m,baseStr[i],vis);

            ans+=mini;
        }


        return ans;
        
    }
};