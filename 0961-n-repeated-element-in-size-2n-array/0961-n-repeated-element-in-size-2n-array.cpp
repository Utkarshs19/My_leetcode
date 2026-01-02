class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n=nums.size();
        n=n/2;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[i+n-1])
            return nums[i];
        }

        return -1;


    }
};