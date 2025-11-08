class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                set<int> s1,s2;

                    for(int a=i-1,b=j-1;a>=0&&b>=0;a--,b--)
                    {
                        s1.insert(grid[a][b]);
                    }
                

                 for(int a=i+1,b=j+1;a<n&&b<m;a++,b++)
                    {
                        s2.insert(grid[a][b]);
                    }
                

                    ans[i][j]=abs((int)s1.size()-(int)s2.size());
            }
        }
        

        return ans;
    }
};