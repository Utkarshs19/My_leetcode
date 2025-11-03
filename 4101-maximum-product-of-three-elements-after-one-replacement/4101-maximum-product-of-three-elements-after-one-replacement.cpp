class Solution {
public:
    long long maxProduct(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            nums[i]=nums[i]*-1;
        }

        sort(nums.begin(),nums.end());

        return (long long)100000*nums[nums.size()-1]*nums[nums.size()-2];
        
    }
};