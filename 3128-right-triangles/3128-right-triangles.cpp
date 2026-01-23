class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>> v1(n,vector<pair<int,int>>(m,{0,0})),v2(n,vector<pair<int,int>>(m,{0,0}));

       


        for(int i=0;i<grid.size();i++)
        {
            int s=accumulate(grid[i].begin(),grid[i].end(),0);
            int cnt=0;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    s--;
                    v1[i][j]={cnt,s};
                    cnt++;
                }
            }
        }

        for(int i=0;i<grid[0].size();i++)
        {
            int s=0;
            for(int j=0;j<grid.size();j++)
            s+=grid[j][i];

            int cnt=0;
            for(int j=0;j<grid.size();j++)
            {
                if(grid[j][i]==1)
                {
                    s--;
                   v2[j][i]={cnt,s};
                    cnt++;
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
                    int left=v1[i][j].first;
                    int right=v1[i][j].second;

                    int up=v2[i][j].first;
                    int down=v2[i][j].second;

                    ans+=(left*up);
                    ans+=(left*down);
                    ans+=(right*up);
                    ans+=(right*down);
                }

            }
        }
        
            

        return ans;
        
    }
};