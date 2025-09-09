class Solution {
public:
    const long long MOD=1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {

        if(n==1)return 1;

        vector<long long> dp(n+1,0);

        dp[1]=1;

        

        for(int i=2;i<=n;++i)
        {
           if(i-delay>=1)dp[i]++;

           for(int j=max(1,i-forget+1);j<=max(1,i-delay);j++)
           dp[i]=(dp[i]%MOD+dp[j]%MOD)%MOD;

           if(i-forget>=1)dp[i]--;
        }

        return dp[n]%MOD;
        
        
    }
};