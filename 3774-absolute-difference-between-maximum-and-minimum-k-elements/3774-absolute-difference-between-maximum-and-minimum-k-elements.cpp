class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        int sum1=0,sum2=0;

        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1;

        while(k>0)
        {
            sum1+=nums[i];i++;
            sum2+=nums[j];j--;
            k--;
        }
        return sum2-sum1;


        
    }
};