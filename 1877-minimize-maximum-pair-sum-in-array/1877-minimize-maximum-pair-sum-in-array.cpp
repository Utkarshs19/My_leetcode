class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MIN;
        while(low<high)
        {
            ans=max(ans,(nums[low]+nums[high]));
            low++;
            high--;
        }

        return ans;
        
    }
};