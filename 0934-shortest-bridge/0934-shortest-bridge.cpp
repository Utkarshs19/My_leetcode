class Solution {
public:
    queue<pair<int,int>> q;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        q.push({i,j});
        grid[i][j]=2;

        int n=grid.size();
        int m=grid[0].size();

        if(i+1<n && grid[i+1][j]==1)
        dfs(i+1,j,grid);

        if(i-1>=0 && grid[i-1][j]==1)
        dfs(i-1,j,grid);

        if(j+1<m && grid[i][j+1]==1)
        dfs(i,j+1,grid);

        if(j-1>=0 && grid[i][j-1]==1)
        dfs(i,j-1,grid);

    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        bool flag=false;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                dfs(i,j,grid);
                flag=true;
                break;
                }
            }
            if(flag)break;
        }

        int ans=0;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for (auto &d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    if (grid[nx][ny] == 1)
                        return ans;   

                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }

            }
            ans++;
        }
     
        return -1;
        
    }
};