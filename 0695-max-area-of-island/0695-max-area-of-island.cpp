class Solution {
public:

    vector<vector<int>> vis;
    int n,m;

    void dfs(int i,int j,vector<vector<int>> &grid,int &cnt)
    {
        vis[i][j]=1;
        cnt++;

        if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]==1)
        dfs(i-1,j,grid,cnt);

        if(i+1<n && vis[i+1][j]==0 && grid[i+1][j]==1)
        dfs(i+1,j,grid,cnt);

        if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]==1)
        dfs(i,j-1,grid,cnt);

        if(j+1<m && vis[i][j+1]==0 && grid[i][j+1]==1)
        dfs(i,j+1,grid,cnt);


    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        this->n=grid.size();
        this->m=grid[0].size();
        int ans=0;

        vis.resize(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(i,j,grid,cnt);
                    ans=max(ans,cnt);
                }
            }
        }

        return ans;
                
    }
};