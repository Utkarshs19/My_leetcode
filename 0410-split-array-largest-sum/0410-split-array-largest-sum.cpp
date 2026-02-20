class Solution {
public:
    bool helper(long long mid,vector<int>& nums,int k)
    {
        long long sum=0;
        int cnt=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                sum=nums[i];
                cnt++;
            }
        }

        return cnt+1<=k;
    }
    int splitArray(vector<int>& nums, int k) {

        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0);

        int ans;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;

            if(helper(mid,nums,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return ans;
    }
};