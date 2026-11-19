class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        

        return min({nums[nums.size()-1]-nums[2] ,nums[n-3]-nums[0],nums[n-2]-nums[1]});

    }
};