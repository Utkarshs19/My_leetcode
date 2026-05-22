class Solution {
public:

    int n, m;

    set<string> st;

    vector<vector<int>> vis;

    void dfs(int i, int j,
             vector<vector<int>> &grid,
             string &s,
             char dir)
    {
        vis[i][j] = 1;

        s += dir;

        if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j])
            dfs(i-1,j,grid,s,'U');

        if(i+1<n && grid[i+1][j]==1 && !vis[i+1][j])
            dfs(i+1,j,grid,s,'D');

        if(j-1>=0 && grid[i][j-1]==1 && !vis[i][j-1])
            dfs(i,j-1,grid,s,'L');

        if(j+1<m && grid[i][j+1]==1 && !vis[i][j+1])
            dfs(i,j+1,grid,s,'R');

        s += 'B'; 
    }

    int numDistinctIslands(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vis.resize(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    string s;

                    dfs(i,j,grid,s,'S');

                    st.insert(s);
                }
            }
        }

        return st.size();
    }
};