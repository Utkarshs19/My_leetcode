class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int sum=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        
        int ans=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            left+=nums[i];
            sum=sum-nums[i];

            if(abs(sum-left)%2==0)ans++;
        }
        
        return ans;
    }
};