class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        int sum1=0;

        bool flag=true;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            {
                flag=!flag;
            }
            if(i%6==5)
            {
                flag=!flag;
            }
            if(flag)
            sum1+=nums[i];
        }

        return sum1-(sum-sum1);

    }
};