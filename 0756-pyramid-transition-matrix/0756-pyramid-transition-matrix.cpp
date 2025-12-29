class Solution {
public:
    map<string,vector<char>> m;
    unordered_map<string,bool> dp;

    void helper(int i,string bottom,string s,vector<string>& next)
    {
        if(i==bottom.length()-1)
        {
            next.push_back(s);return;
        }

        string key=bottom.substr(i,2);
        if(m.find(key)==m.end())return;

        for(auto c:m[key])
        {
            helper(i+1,bottom,s+c,next);
        }

    
    }

    bool dfs(string bottom)
    {
        if(bottom.length()==1)return true;
        if(dp.count(bottom))return dp[bottom];
        vector<string> next;

        helper(0,bottom,"",next);

        for(auto& i:next)
        {
            if(dfs(i))return dp[bottom]=true;
        }
        return dp[bottom]=false;

    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        int len=bottom.length();
        for(int i=0;i<allowed.size();i++)
        {
            string s="";
            s+=allowed[i][0];
            s+=allowed[i][1];

            m[s].push_back(allowed[i][2]);
        }

        return dfs(bottom);
        
        
    }
};