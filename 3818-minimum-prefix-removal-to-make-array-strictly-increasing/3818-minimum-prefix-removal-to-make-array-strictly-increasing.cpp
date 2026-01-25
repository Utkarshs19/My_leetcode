class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int i;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i]<=nums[i-1])
            {
                break;
            }
        }
        return i;
        
    }
};