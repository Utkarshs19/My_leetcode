class Solution {
public:

    
    int n,m;
    int k;
    int helper(int i,int j,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
    {
        if(i>=n || j>=m)return -1e9;
        
        c+=(grid[i][j]!=0);

        if(c>k)return -1e9;

        if(i==n-1 && j==m-1)
        {
            return grid[i][j];
        }

        if(dp[i][j][c]!=-1)return dp[i][j][c];

        int right=grid[i][j]+helper(i,j+1,c,grid,dp);
        int down= grid[i][j]+helper(i+1,j,c,grid,dp);

        return dp[i][j][c]=max(right,down);

    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        n=grid.size();
        m=grid[0].size();   
        this->k=k;
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        int ans=helper(0,0,0,grid,dp);

        
        return ans>=0?ans:-1;

        
    }
};