class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int helper(int i,int j,vector<vector<int>> &matrix)
    {
        if(dp[i][j]!=-1)return dp[i][j];

        int cnt=1;

        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
        cnt=max(cnt,1+helper(i-1,j,matrix));

        if(i+1<n && matrix[i+1][j]>matrix[i][j])
        cnt=max(cnt,1+helper(i+1,j,matrix));

        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
        cnt=max(cnt,1+helper(i,j-1,matrix));

        if(j+1<m && matrix[i][j+1]>matrix[i][j])
            cnt=max(cnt,1+helper(i,j+1,matrix));


        return dp[i][j]=cnt;
        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        dp.resize(n,vector<int>(m,-1));

        int ans=INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                {
                    ans=max(ans,helper(i,j,matrix));
                }
            }
        }
        return ans;
    }
};