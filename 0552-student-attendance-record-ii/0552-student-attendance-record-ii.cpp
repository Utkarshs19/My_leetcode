class Solution {
public:

    long long dp[100001][2][3];
    const long long mod=1e9+7;
    int helper(int i,int n,int a,int l)
    {
        if(i==n)
        {
            return 1;
        }

        if(dp[i][a][l]!=-1)return dp[i][a][l];

        long long ans=helper(i+1,n,a,0);
        if(a==0)
            ans+=helper(i+1,n,a+1,0);
        if(l<2)
            ans+=helper(i+1,n,a,l+1);

        return dp[i][a][l]=ans%mod;
    }

    int checkRecord(int n) {
        
        memset(dp,-1,sizeof(dp));
        return helper(0,n,0,0);

    }
};