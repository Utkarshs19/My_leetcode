class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int i=0,j=0;
        long long ans=0;

        while(j<nums.size())
        {
            if(nums[j]>=minK && nums[j]<=maxK)j++;
            else
            {
                int size=j-i;
                ans+=(1ll*size*(size+1)/2);
                j++;
                i=j;
            }
        }
        int size=j-i;
        ans+=(1ll*size*(size+1)/2);
        return ans;
        
    }
};