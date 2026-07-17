class Solution {
public:

    int dp[1001][1001][3];
    vector<int> pref;
    int solve(int i,int j)
    {
    return pref[j+1]-pref[i];
    }
    int helper(int i,int j,int flag,vector<int> &stones)
    {   
        if(i==j)return 0;

        if(dp[i][j][flag]!=-1)return dp[i][j][flag];

        if(flag==1)
        {
            int a=helper(i+1,j,1-flag,stones)+(solve(i+1,j));
            int b=helper(i,j-1,1-flag,stones)+(solve(i,j-1));

            return dp[i][j][flag]=max(a,b);
        }
        else
        {
            int a=helper(i+1,j,1-flag,stones)-solve(i+1,j);
            int b=helper(i,j-1,1-flag,stones)-solve(i,j-1);

            return dp[i][j][flag]=min(a,b);
        }
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        memset(dp,-1,sizeof(dp));
        pref.resize(n+1,0);

        for(int i=0;i<n;i++)
        {
            pref[i+1]=pref[i]+stones[i];
        }

        return helper(0,n-1,1,stones);
    }
};