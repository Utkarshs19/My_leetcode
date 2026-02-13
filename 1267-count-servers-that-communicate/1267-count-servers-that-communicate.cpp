class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)continue;

                bool found=false;
                for(int row=0;row<n;row++)
                {
                    if(row!=i && grid[row][j]==1)
                    {
                        found=true;
                        break;
                    }
                }
                if(!found)
                {
                    for(int col=0;col<m;col++)
                    {
                        if(col!=j && grid[i][col]==1)
                        {
                            found=true;
                            break;
                        }
                    }
                }
                if(found)ans++;
            }
        }

        return ans;
        
    }
};