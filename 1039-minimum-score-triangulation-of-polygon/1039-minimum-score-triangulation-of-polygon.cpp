class Solution {
public:

    vector<vector<int>> dp;

    int helper(int i,int j,vector<int>&values)
    {
        if(j-i<2)return dp[i][j]=0;
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        
        int res=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            res=min(res,values[i]*values[j]*values[k]+helper(i,k,values)+helper(k,j,values));
        }

        return dp[i][j]=res;
    }

    int minScoreTriangulation(vector<int>& values) {
        
        dp.resize(51,vector<int>(51,INT_MAX));
        int n=values.size();
        return helper(0,n-1,values);

    }
};