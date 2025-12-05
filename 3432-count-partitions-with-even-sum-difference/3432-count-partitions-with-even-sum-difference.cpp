class Solution {
public:
    int countPartitions(vector<int>& nums) {
        

        int sum=accumulate(nums.begin(),nums.end(),0);

        sum=sum-nums[0];
        int ans=0;

        int n=nums.size();

        int tot=nums[0];

        for(int i=1;i<n;i++)
        {
            if((sum-tot)%2==0)
            {
                ans++;
            }
            sum=sum-nums[i];
            tot+=nums[i];
        }

        return ans;


    }
};