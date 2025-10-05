class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        long long int pro=1;
        int mod=12345;

        vector<vector<int>> ans(n,vector<int>(m));

        vector<vector<int>> pre(n,vector<int>(m));

        vector<vector<int>> suf(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pre[i][j]=pro;
                pro=pro*grid[i][j];
                pro=pro%mod;
            }
        }

        pro=1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                suf[i][j]=pro;
                pro=pro*grid[i][j];
                pro=pro%mod;
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                long long int m=pre[i][j]*suf[i][j];

                ans[i][j]=m%12345;
            }
            // cout<<endl;
        }

        return ans;

    }
};