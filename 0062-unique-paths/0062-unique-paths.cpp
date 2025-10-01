class Solution {
public:

    int helper(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n)return 0;

        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];


        int down=0,right=0;

        down+=helper(i+1,j,m,n,dp);
        right+=helper(i,j+1,m,n,dp);

        return dp[i][j]=down+right;
    }
    
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int k=0;k<n;k++)
        dp[m][k]=0;

        for(int k=0;k<m;k++)
        {
            dp[k][n]=0;
        }


        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {

                if(i==m-1 && j==n-1){
                    dp[i][j]=1;
                    continue;
                }
                int down=0;
                int right=0;

                down+=dp[i+1][j];
                right+=dp[i][j+1];

                dp[i][j]=down+right;
            }
        }



        return dp[0][0];
        
    }
};