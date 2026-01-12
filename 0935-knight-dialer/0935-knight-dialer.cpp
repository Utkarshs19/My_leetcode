class Solution {
public:
    map<int,vector<int>> m;

    const int mod=1000000007;

    vector<vector<int>> dp;

    int dfs(int n,int i)
    {
        if(n==1)
        {
            return 1;
        }

        if(dp[n][i]!=-1)return dp[n][i];

        long long x=0;

        for(auto j:m[i])
        {
            x = (x + dfs(n - 1, j)) % mod;
        }

        return dp[n][i]=x;
    }

    int knightDialer(int n) {

        dp.resize(5001,vector<int>(10,-1));

        m[0]={4,6};
        m[1]={6,8};
        m[2]={7,9};
        m[3]={4,8};
        m[4]={3,9,0};
        m[5]={};
        m[6]={1,0,7};
        m[7]={2,6};
        m[8]={1,3};
        m[9]={4,2};

        long long ans=0;

        for(int i=0;i<=9;i++)
        {
            ans=(ans+dfs(n,i))%mod;
        }

        return ans;

        
    }
};