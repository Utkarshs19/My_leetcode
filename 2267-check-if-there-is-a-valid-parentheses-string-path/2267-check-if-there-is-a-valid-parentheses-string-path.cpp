class Solution {
public:
    int n,m;
    int dp[101][101][201];
    bool helper(int i,int j,int cnt,vector<vector<char>> &grid)
    {
        cnt+=(grid[i][j]=='(')?1:-1;
        if(cnt<0)return false;

        if(i==n-1 && j==m-1)
        {
            return dp[i][j][cnt]=(cnt==0);
        }
        if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];

        bool res=false;
        if(i+1<n)
        {
            res=res|helper(i+1,j,cnt,grid);
        }
        if(j+1<m)
        {
            res=res|helper(i,j+1,cnt,grid);
        }

        return dp[i][j][cnt]= res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        this->n=grid.size();
        this->m=grid[0].size();

        int cnt=0;
        memset(dp,-1,sizeof(dp));

        return helper(0,0,cnt,grid);


    }
};