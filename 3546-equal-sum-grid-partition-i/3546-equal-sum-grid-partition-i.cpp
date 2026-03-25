class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long  total=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
        total+=accumulate(grid[i].begin(),grid[i].end(),0ll);
        }
        long long sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=accumulate(grid[i].begin(),grid[i].end(),0ll);

            if(sum==total-sum)return true;
        }
        sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=grid[j][i];
            }
            if(sum==total-sum)return true;
        }

        return false;
        
    }
};