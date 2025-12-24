class Solution {
public:

    int x=-1;
    int y=-1;

    int n,m;

    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        vis[i][j]=1;

        if(i==n-1 && j==m-1)
        {
            x=n-1;
            y=m-1;
            return;
        }

        if(i-1>=0 && vis[i-1][j]==-1)
        {
            if(grid[i][j]==2 && (grid[i-1][j]==2 ||grid[i-1][j]==3 || grid[i-1][j]==4))dfs(i-1,j,grid,vis);
            if(grid[i][j]==5 &&(grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))dfs(i-1,j,grid,vis);
            if(grid[i][j]==6 &&(grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))dfs(i-1,j,grid,vis);
        }

        if(i+1<n && vis[i+1][j]==-1)
        {
            
            if(grid[i][j]==2 && (grid[i+1][j]==2 ||grid[i+1][j]==5 || grid[i+1][j]==6))dfs(i+1,j,grid,vis);
            if(grid[i][j]==3 && (grid[i+1][j]==5 || grid[i+1][j]==6 ||grid[i+1][j]==2))dfs(i+1,j,grid,vis);
            if(grid[i][j]==4 && (grid[i+1][j]==5 || grid[i+1][j]==6 ||grid[i+1][j]==2))dfs(i+1,j,grid,vis);
        }

        if(j-1>=0 && vis[i][j-1]==-1)
        {

             if(grid[i][j]==1 && (grid[i][j-1]==4 || grid[i][j-1]==6 || grid[i][j-1]==1))dfs(i,j-1,grid,vis);
            if(grid[i][j]==3 && (grid[i][j-1]==1 || grid[i][j-1]==4 ||grid[i][j-1]==6))dfs(i,j-1,grid,vis);
            
            if(grid[i][j]==5 && (grid[i][j-1]==1 || grid[i][j-1]==4 ||grid[i][j-1]==6))dfs(i,j-1,grid,vis);

        }

        if(j+1<m && vis[i][j+1]==-1)
        {
            if(grid[i][j]==1 && (grid[i][j+1]==3 || grid[i][j+1]==5 || grid[i][j+1]==1))dfs(i,j+1,grid,vis);
            if(grid[i][j]==4 && (grid[i][j+1]==1 || grid[i][j+1]==3 ||grid[i][j+1]==5))dfs(i,j+1,grid,vis);
            
            
            if(grid[i][j]==6 && (grid[i][j+1]==1 || grid[i][j+1]==3 ||grid[i][j+1]==5))dfs(i,j+1,grid,vis);
        }



    }

    bool hasValidPath(vector<vector<int>>& grid) {

        n=grid.size();
        m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));

        dfs(0,0,grid,vis);

        return x==n-1 && y==m-1;

        
    }
};