class Solution {
public:

    int n,m;

    void dfs(int i,int j,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             long long &sum,
             long long &cnt)
    {
        vis[i][j] = 1;

        sum += grid[i][j];

        cnt++;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int k=0;k<4;k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni>=0 && ni<n &&
               nj>=0 && nj<m &&
               !vis[ni][nj] &&
               grid[ni][nj]!=-1)
            {
                dfs(ni,nj,grid,vis,sum,cnt);
            }
        }
    }

    long long sumRemoteness(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        long long total = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] != -1)
                    total += grid[i][j];
            }
        }

        vector<vector<int>> vis(n, vector<int>(m,0));

        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=-1 && !vis[i][j])
                {
                    long long compSum = 0;
                    long long compSize = 0;

                    dfs(i,j,grid,vis,compSum,compSize);

                    ans += compSize * (total - compSum);
                }
            }
        }

        return ans;
    }
};