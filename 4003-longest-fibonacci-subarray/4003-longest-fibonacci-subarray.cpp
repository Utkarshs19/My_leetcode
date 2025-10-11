class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int prev2=nums[0];
        int prev1=nums[1];

        int ans=2;
        int cur=2;

        for(int i=2;i<nums.size();i++)
        {
            if(prev1+prev2==nums[i])
            {
                cur++;
                ans=max(ans,cur);
            }
            else
            {
                cur=2;
                ans=max(ans,cur);
            }

            prev2=prev1;
            prev1=nums[i];
        }

        return ans;
        
    }
};