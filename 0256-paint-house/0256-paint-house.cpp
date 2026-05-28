class Solution {
public:
    int dp[101][4];
    int helper(int i,vector<vector<int>>& costs,int col)
    {
        if(i==costs.size())return 0;
       
        if(dp[i][col+1]!=-1)return dp[i][col+1];
        
        int ans=1e9;

        for(int j=0;j<3;j++)
        {
            if(j==col)continue;
            
            ans=min(ans,costs[i][j]+helper(i+1,costs,j));
        }

        return dp[i][col+1]=ans;
    }
    int minCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));

        return helper(0,costs,-1);
    }
};