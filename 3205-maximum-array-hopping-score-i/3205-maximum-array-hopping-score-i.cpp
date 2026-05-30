class Solution {
public:
    int maxScore(vector<int>& nums) {

        int n=nums.size();

        vector<int> dp(n,0);

        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                dp[i]=max(dp[i],(dp[j]+(i-j)*nums[i]));
            }
        }

        return dp[n-1];
        
    }
};