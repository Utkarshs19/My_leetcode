class Solution {
public:

    vector<vector<int>> dp;
    int x=10000;

    int helper(int i,vector<int>&nums,int target,int sum)
    {
        if(i>=nums.size())
        {
            if(sum==target)return 1;
            else 
            return 0;
        }

        if(dp[i][sum+x]!=-1)return dp[i][sum+x];

        int plus=helper(i+1,nums,target,sum+nums[i]);
        int minus=helper(i+1,nums,target,sum-nums[i]);

        return dp[i][sum+x]=plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        dp.resize(21,vector<int>(20001,-1));

        return helper(0,nums,target,0);
        
    }
};