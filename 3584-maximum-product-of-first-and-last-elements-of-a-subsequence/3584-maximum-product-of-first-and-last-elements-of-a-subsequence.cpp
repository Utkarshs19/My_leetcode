class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {

        long long ans = 1ll*nums[0]*nums[m-1];

        long long mn = nums[0];
        long long mx = nums[0];

        for(int j = m; j < nums.size(); j++)
        {
            mn = min(mn, 1LL * nums[j-m+1]);

            mx = max(mx, 1LL * nums[j-m+1]);

            ans = max(ans, 1ll*mn * nums[j]);

            ans = max(ans, 1ll*mx * nums[j]);
        }
        return ans;
        
    }
};