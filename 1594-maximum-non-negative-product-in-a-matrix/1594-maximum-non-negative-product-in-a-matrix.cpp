class Solution {
public:
    int n,m;
    long long ans=-1;

    void helper(int i,int j,long long pro,vector<vector<int>> &grid)
    {
        if(i>=n || j>=m)return;
        if(grid[i][j]==0)
        {
            ans=max(ans,1ll*0);
            return;
        }
        pro=pro*grid[i][j];
        if(i==n-1 && j==m-1)
        {
            ans=max(ans,pro);
            return;
        }

        helper(i+1,j,pro,grid);
        helper(i,j+1,pro,grid);
    }

    int maxProductPath(vector<vector<int>>& grid) {

        n=grid.size();
        m=grid[0].size();

        helper(0,0,1,grid);

        return (ans<0?-1:(int)(ans%(long)(1e9+7)));
        
    }
};