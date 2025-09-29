class Solution {
public:

    int helper(vector<vector<int>> &grid,int x,int y)
    {
        int ans=0;

        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i<=n/2 && (i==j || i+j==n-1)) || (i>n/2 && j==n/2))
                {
                    if(grid[i][j]!=x)
                    ans++;
                }
                else
                {
                    if(grid[i][j]!=y)
                    ans++;
                }
            }
        }

        return ans;
    }

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {

        return  min({helper(grid,0,1),helper(grid,1,0),helper(grid,0,2),
                     helper(grid,2,0),helper(grid,2,1),helper(grid,1,2)});
        
    }
};