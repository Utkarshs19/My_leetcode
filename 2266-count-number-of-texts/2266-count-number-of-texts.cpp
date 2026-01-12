class Solution {
public:
    const int mod=1000000007;

    vector<int> dp;
       

    int helper(int i,string &s)
    {
        if(i==s.length())return 1;

        if(dp[i]!=-1)return dp[i];

        long long x=0;

        int limit=(s[i]=='7' || s[i]=='9')?4:3;

        for(int k=1;k<=limit && i+k<=s.length();k++)
        {
            if(s[i+k-1]!=s[i])break;
            x=(x+helper(i+k,s))%mod;
        }

        return dp[i]=x;


    }

    int countTexts(string pressedKeys) {

        dp.resize(100001,-1);
        return helper(0,pressedKeys);
        
    }
};