class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;

    int helper(int i,int c1,int c2,vector<vector<int>> &grid)
    {
        if(i>=n || i<0 || c1>=m || c2>=m ||c1<0 || c2<0)return 0;

        if(i==n-1)
        {
            dp[i][c1][c2]=grid[i][c1];
            if(c1!=c2)
            dp[i][c1][c2]+=grid[i][c2];

            return dp[i][c1][c2];
        }

        if(dp[i][c1][c2]!=-1)return dp[i][c1][c2];

        int sum=grid[i][c1];
        if(c1!=c2)sum+=grid[i][c2];

        sum+=max({
            helper(i+1,c1-1,c2-1,grid),
            helper(i+1,c1-1,c2,grid),
            helper(i+1,c1-1,c2+1,grid),
            helper(i+1,c1,c2-1,grid),
            helper(i+1,c1,c2,grid),
            helper(i+1,c1,c2+1,grid),
            helper(i+1,c1+1,c2-1,grid),
            helper(i+1,c1+1,c2,grid),
            helper(i+1,c1+1,c2+1,grid)
        });

        return dp[i][c1][c2]=sum;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        dp.resize(71,vector<vector<int>>(71,vector<int>(71,-1)));

        return helper(0,0,m-1,grid);

    }
};