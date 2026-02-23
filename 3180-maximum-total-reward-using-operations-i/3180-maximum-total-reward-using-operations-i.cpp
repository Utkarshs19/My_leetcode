class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i, int sum, vector<int>& nums) {

        if (i >= nums.size())
            return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int take = 0;
        int notTake;

        if (sum < nums[i]) 
            take = nums[i] + helper(i + 1, sum + nums[i], nums);

        notTake = helper(i + 1, sum, nums);

        return dp[i][sum] = max(take, notTake);
    }

    int maxTotalReward(vector<int>& rewardValues) {

        sort(rewardValues.begin(), rewardValues.end());

        int n = rewardValues.size();

        dp.resize(n, vector<int>(5000, -1));

        return helper(0, 0, rewardValues);
    }
};