class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<int> v1(n,0);
        vector<int> v2(m,0);

       


        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                   v1[i]++;
                   v2[j]++;
                }
            }
        }


        long long ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                if(grid[i][j]==1)
                {
                  ans+=((v1[i]-1)*(v2[j]-1));
                }

            }
        }
            

        return ans;
        
    }
};