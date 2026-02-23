class Solution {
public:
    int func(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp) {

        if (ind >= nums.size())
            return 0;

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int take = 0;
        int notTake;

        if (sum < nums[ind]) {
            take = nums[ind] + func(ind + 1, sum + nums[ind], nums, dp);
        }

        notTake = func(ind + 1, sum, nums, dp);

        return dp[ind][sum] = max(take, notTake);
    }

    int maxTotalReward(vector<int>& rewardValues) {

        sort(rewardValues.begin(), rewardValues.end());

        int n = rewardValues.size();

        vector<vector<int>> dp(n, vector<int>(5000, -1));

        return func(0, 0, rewardValues, dp);
    }
};