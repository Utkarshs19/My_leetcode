class Solution {
public:
    int dp[1001][1001];

    int helper(int i,vector<int> &nums,int target)
    {
        if(target==0)return 0;
        if(i>=nums.size() || target<0)return -1001;

        if(dp[i][target]!=-1)return dp[i][target];
       
        int take=1+helper(i+1,nums,target-nums[i]);
        int not_take=helper(i+1,nums,target);

        return dp[i][target]=max(take,not_take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        memset(dp,-1,sizeof(dp));

         int ans=helper(0,nums,target);

        return (ans>0)?ans:-1;
    }
};