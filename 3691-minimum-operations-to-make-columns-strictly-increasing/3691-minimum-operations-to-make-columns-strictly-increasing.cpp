class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int ans=0;

        for(int i=1;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i-1][j]<grid[i][j])continue;
                else
                {
                    ans+=(grid[i-1][j]-grid[i][j]+1);
                grid[i][j]+=(grid[i-1][j]-grid[i][j]+1);
                }
            }
        }

        return ans;
        
    }
};