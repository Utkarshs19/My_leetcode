class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        int n=nums.size();

        int med=n/2;

        long long cnt=0;

        if(nums[med]==k)return 0;

        for(int i=0;i<med;i++)
        {
            if(nums[i]>k)
            {
                cnt+=nums[i]-k;
                nums[i]=k;
            }
        }

        cnt+=abs(nums[med]-k);

        for(int i=med+1;i<n;i++)
        {
            if(nums[i]<k)
            {
                cnt+=abs(nums[i]-k);
            }
        }

        return cnt;
    }
};