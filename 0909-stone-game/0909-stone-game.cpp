class Solution {
public:

    long long helper(int i,int j,vector<int> &piles,vector<vector<long long>> &dp)
    {
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        long long  first=piles[i]+min(helper(i+2,j,piles,dp),helper(i+1,j-1,piles,dp));

        long long  last = piles[j]+min(helper(i+1,j-1,piles,dp),helper(i,j-2,piles,dp));

        return dp[i][j]=max(first,last);
    }

    bool stoneGame(vector<int>& piles) {

        vector<vector<long long >> dp(505,vector<long long>(505,-1));

        long long sum=accumulate(piles.begin(),piles.end(),0);

        long long res=helper(0,piles.size()-1,piles,dp);

        if(res > sum-res)
        return true;
        else
        return false;
        
    }
};