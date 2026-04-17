class Solution {
public:
    unordered_set<string> st;
    unordered_map<string,bool> dp;
    bool helper(string str)
    {
        if(dp.count(str))return dp[str];
        for(int i=1;i<str.length();i++)
        {
            string pre=str.substr(0,i);
            string suf=str.substr(i);

            if((st.count(pre) && st.count(suf) )|| (st.count(pre) && helper(suf)))
            {
                return dp[str]=true;;
            }
        }

        return dp[str]=false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(auto i:words)st.insert(i);
        vector<string> ans;

        for(int i=0;i<words.size();i++)
        {
            if(helper(words[i]))ans.push_back(words[i]);
        }

        return ans;
        
    }
};