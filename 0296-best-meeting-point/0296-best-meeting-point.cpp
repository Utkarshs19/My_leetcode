class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows,cols;
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(cols.begin(),cols.end());
        int r=rows[rows.size()/2];
        int c=cols[cols.size()/2];
        int ans=0;
        for(auto i:rows)
        {
            ans+=(abs(i-r));
        }
        for(auto i:cols)
        {
            ans+=(abs(i-c));
        }
        return ans;
    }
};