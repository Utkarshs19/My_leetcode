class Solution {
public:
    int n, m;
    int dp[1001][1024];    
    int helper(int i, int j, int k, vector<vector<int>>& grid)
    {
        if(i == n-1 && j == m-1)
            return k ^ grid[i][j];

        if(i >= n || j >= m)
            return INT_MAX;

        long long id=i * m + j;
        if(dp[id][k]!=-1) return dp[id][k];

        int cur = k ^ grid[i][j];
        int right = helper(i, j+1, cur, grid);
        int down  = helper(i+1, j, cur, grid);

        if(right == INT_MAX && down == INT_MAX)
            return dp[id][k] = INT_MAX;

        return dp[id][k] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(0, 0, 0, grid);
    }
};