class Solution {
public:

    int helper(int n,int k,int target,vector<vector<int>> &dp)
    {
        if(n==0 && target==0)return 1;
        if(target<0 || n<0 )return 0;
        

        if(dp[n][target]!=-1)return dp[n][target];

        long long ans=0;
        for(int i=1;i<=k;i++)
        {
            ans=(ans+helper(n-1,k,target-i,dp))%1000000007;
        }

        return dp[n][target]=ans%1000000007;

    }

    int numRollsToTarget(int n, int k, int target) {
        

        vector<vector<int>> dp(31,vector<int>(1001,-1));

        return helper(n,k,target,dp)%1000000007;

    }
};