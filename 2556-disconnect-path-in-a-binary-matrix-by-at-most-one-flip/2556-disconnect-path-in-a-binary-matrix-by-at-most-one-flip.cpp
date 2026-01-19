class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    vector<vector<int>> grid;

    bool dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 ||vis[i][j]==1)
            return false;
        if (i == n - 1 && j == m - 1)
            return true;

        vis[i][j] = 1; 

        return dfs(i + 1, j) || dfs(i, j + 1);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        this->grid=grid;
        n = grid.size();
        m = grid[0].size();
        vis.resize(n,vector<int>(m,0));

        if (!dfs(0, 0))
            return true; 

        vis[0][0]=0;
        vis[n-1][m-1]=0;
        return !dfs(0, 0);
    }
};
