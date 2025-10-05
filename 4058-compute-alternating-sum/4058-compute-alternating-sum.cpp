class Solution {
public:
    int alternatingSum(vector<int>& nums) {

        int sum=0;
        int flag=1;

        for(int i=0;i<nums.size();i++)
        {
            sum+=(flag * nums[i]);
            flag=-flag;
        }

        return sum;
        
    }
};