class Solution {
public:

    int helper(int i,int j,int n,int m,vector<vector<int>> &grid, vector<vector<bool>> &flag)
    {
        if(i<0 || i>=n ||j<0 || j>=m)return 0;
        if(flag[i][j] || grid[i][j]==0)return 0;

        flag[i][j]=true;

        long long int ans=0;
        ans=grid[i][j];

            ans+=helper(i-1,j,n,m,grid,flag);

            ans+=helper(i+1,j,n,m,grid,flag);
        
            ans+=helper(i,j-1,n,m,grid,flag);
       
            ans+=helper(i,j+1,n,m,grid,flag);
        

        return ans;

    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> flag(n,vector<bool>(m,false));

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && !flag[i][j])
                {
                    cout<<i<<" "<<j<<endl;
                    if(helper(i,j,n,m,grid,flag)%k==0)
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};