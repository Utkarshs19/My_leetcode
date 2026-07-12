class Solution {
public:
    const int MOD=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        
        long long sum = 0;
        for (int i=0;i<nums.size();i++)
            sum += nums[i];
            
        long long x = (sum + k - 1) / k % MOD;
        return (x - 1) * x / 2 % MOD;
        
    }
};