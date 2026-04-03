class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int i=0,j=0;
        int ans=0;
        while(j<nums.size())
        {
            if(nums[j]==1)j++;
            else
            {
                ans=max(ans,j-i);
                i=j;
                while(i<nums.size() && nums[i]!=1)i++;
                j=i;
            }
        }
        ans=max(ans,j-i);
        return ans;

        
    }
};