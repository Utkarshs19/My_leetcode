class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        sort(nums.rbegin(),nums.rend());
        long long  ans=0;
        for(int i=0;i<k;i++)
        {
            if(mul>0)
            {
                ans+=(1ll*mul*nums[i]);
            }
            else
            ans+=nums[i];

            mul--;
        }

        return ans;
    }
};