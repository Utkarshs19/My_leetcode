class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long int res=0;
        long long int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            sum++;
            else
            {
                long long int x=sum*(sum+1)/2;
                res+=x;
                sum=0;
            }
        }

        if(sum>0)
        {
            long long int x=sum*(sum+1)/2;
            res+=x;
        }

        return res;
        
    }
};