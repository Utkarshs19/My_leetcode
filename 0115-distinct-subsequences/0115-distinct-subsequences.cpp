class Solution {
public:
    int ans=0;
    int dp[1001][1001];
    int helper(int i,int j,string &s,string &t)
    {
        if(j==t.length())return 1;
        if(i==s.length())return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int sum=helper(i+1,j,s,t);

        if(s[i]==t[j])
        {
            sum+=helper(i+1,j+1,s,t);
        }

        return dp[i][j]=sum;
        
    }
    int numDistinct(string s, string t) {
        
        memset(dp,-1,sizeof(dp));
        
        return helper(0,0,s,t);

    }
};