class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int ans=0;

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> v1(n+1,vector<int>(m+1,0));
        vector<vector<int>> v2(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X')v1[i+1][j+1]++;
                if(grid[i][j]=='Y')v2[i+1][j+1]++;
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                v1[i][j]+=v1[i-1][j]+v1[i][j-1]-v1[i-1][j-1];
                v2[i][j]+=v2[i-1][j]+v2[i][j-1]-v2[i-1][j-1];
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(v1[i][j]==v2[i][j]&&v1[i][j]>0)
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};