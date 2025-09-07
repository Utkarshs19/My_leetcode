class Solution {
public:
    int minOperations(vector<int>& nums) {

        bool flag=true;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])flag=false;
        }

        if(flag==false)return 1;
        return 0;
        
    }
};