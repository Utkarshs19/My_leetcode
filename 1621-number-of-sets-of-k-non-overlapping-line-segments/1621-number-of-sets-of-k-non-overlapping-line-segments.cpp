class Solution {
public:
    const int mod=1e9+7;
    int dp[1001][1001];
    int helper(int i,int n,int k)
    {
       if(k==0)return 1;
       if(i>=n)return 0;

        if(dp[i][k]!=-1)return dp[i][k];
       int skip=helper(i+1,n,k);
        int take=0;
       for(int j=i+1;j<n;j++)
       {    
            take=(take+helper(j,n,k-1))%mod;
       }

       return dp[i][k]=(skip+take)%mod;

    
        
    }

    int numberOfSets(int n, int k) {

        if(k==n-1)return 1;
        memset(dp,-1,sizeof(dp));

        return helper(0,n,k);

    }
};