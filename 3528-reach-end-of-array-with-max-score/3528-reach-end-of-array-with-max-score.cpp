class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {

        long long ans=0;
        int x=0;

        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[x])
            {
                ans+=(long long)((long long )(i-x)*nums[x]);
                x=i;
            }
        }

        ans+=(long long)((long long)(nums.size()-1-x))*nums[x];

        return ans;


        
    }
};