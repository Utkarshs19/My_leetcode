class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int ans=0;

        int min_x=1001;
        int min_y=1001;
        int max_x=-1;
        int max_y=-1;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    min_x=min(min_x,j);
                    min_y=min(min_y,i);
                    max_x=max(max_x,j);
                    max_y=max(max_y,i);

                    
                }
            }
        }

        ans=(max_x-min_x+1)*(max_y-min_y+1);

        return ans;
        
    }
};