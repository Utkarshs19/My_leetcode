class Solution {
public:
    vector<vector<int>> mat;
    int target;
    int ans=1e9;
    int m,n;
    vector<vector<int>> dp;
    void helper(int ind ,int sum)
    {
        if(ind==n)
        {
            ans=min(ans,abs(target-sum));
            return;
        }

        if(dp[ind][sum])return;

        dp[ind][sum]=1;

        for(int j=0;j<m;j++)
        {
            helper(ind+1,sum+mat[ind][j]);
        }
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->mat=mat;
        this->target=target;
        this->n=mat.size();
        this->m=mat[0].size();
        dp.resize(n,vector<int>(5001,0));
        helper(0,0);
        return ans;
    }
};